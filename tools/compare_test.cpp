#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

int casen();
void gencase(int _case);

const string testcase_fn = "tools/test/test.txt";
const string output1_fn = "tools/test/out1.txt";
const string output2_fn = "tools/test/out2.txt";

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

string getoutput_2() {
    static auto cmd = "build/compro2 < " + testcase_fn + " > " + output2_fn;
    std::system(cmd.c_str());
    return read_file(output2_fn);
}

int main() {
    auto defout = cout.rdbuf();
    int wa = 0;

    cout << "start compare test" << endl;

    for (int _case = 0; _case < casen(); _case++) {
        {
            ofstream ofs(testcase_fn);
            cout.rdbuf(ofs.rdbuf());
            gencase(_case);
            cout.rdbuf(defout);
            if (ofs.tellp() == 0)
                cout << "empty case" << endl;
        }
        {
            auto test = read_file(testcase_fn);
            auto out1 = getoutput_1();
            auto out2 = getoutput_2();

            if (out1 != out2) {
                wa++;
                cout << "WA" << endl;
                cout << "testcase:\n"
                     << test << endl;
                cout << "output main.cpp:\n"
                     << out1 << endl;
                cout << "output main2.cpp:\n"
                     << out2 << endl;
            }
        }
    }
    if (wa > 0)
        cout << "WA: " << wa << endl;
    else
        cout << "all test passed" << endl;
}
