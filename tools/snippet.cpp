#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
namespace fs = filesystem;

string mls(string s) {
    string t;
    auto it = s.begin();
    while (it < s.end()) {
        auto it2 = find(it, s.end(), '\n');
        t += "\"";
        t += string_view(it, it2);
        t.pop_back();
        t += "\",\n";
        if (it2 != s.end())
            it2++;
        it = it2;
    }
    if (!t.empty()) {
        t.pop_back();
        t.pop_back();
    }
    return t;
}

int main() {
    cout << "updating..." << endl;

    vector<string> s;

    for (auto f : fs::directory_iterator("snippet")) {
        auto fn = f.path().filename().string();
        if (fn[0] == '.')
            continue;

        ifstream ifs(f.path());
        string buf(f.file_size(), ' ');
        ifs.read(buf.data(), f.file_size());
        while (!buf.empty() && (buf.back() == ' ' || buf.back() == '\n'))
            buf.pop_back();

        ostringstream ss;

        ss << "\"" << fn << "\": {"
                            "\"prefix\": \"lib"
           << fn << "\","
                    "\"body\": ["
           << mls(buf) << "]"
                          "}"
           << endl;

        s.push_back(ss.str());
        cout << "done: " << fn << endl;
    }

    ofstream ofs(".vscode/snippet.code-snippets");

    ofs << "{" << endl;

    for (int i = 0; i < s.size(); i++) {
        ofs << s[i] << (i + 1 == s.size() ? "\n" : ",\n");
    }

    ofs << "}" << endl;
    return 0;
}
