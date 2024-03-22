#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

void gencase();
bool validation();

const string testcase_fn = "tools/test/test.txt";
const string output1_fn = "tools/test/out1.txt";

string read_file(string fn) {
    ifstream ifs(fn);
    return string(istreambuf_iterator<char>(ifs),
                  istreambuf_iterator<char>());
}

string getoutput_1() {
    static auto cmd = "build/compro < " + testcase_fn + " > " + output1_fn;
    std::system(cmd.c_str());
    return read_file(output1_fn);
}

int main() {
    auto defout = cout.rdbuf();
    int wa = 0;

    cout << "start validation test" << endl;

    for (int _ = 0; _ < 100; _++) {
        {
            ofstream ofs(testcase_fn);
            cout.rdbuf(ofs.rdbuf());
            gencase();
            cout.rdbuf(defout);
            if (ofs.tellp() == 0)
                cout << "empty case" << endl;
        }
        {
            auto test = read_file(testcase_fn);
            auto out1 = getoutput_1();

            istringstream iss;
            iss.str(test + '\n' + out1);
            cin.rdbuf(iss.rdbuf());
            bool validation_result = validation();

            if (!validation_result) {
                wa++;
                cout << "WA" << endl;
                cout << "testcase:\n"
                     << test << endl;
                cout << "output:\n"
                     << out1 << endl;
            }
        }
    }
    if (wa > 0)
        cout << "WA: " << wa << endl;
    else
        cout << "all test passed" << endl;
}
