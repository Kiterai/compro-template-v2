#include <fstream>
#include <iostream>
#include <random>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, ini, n) for (int i = (ini); i < (n); i++)

struct {
    std::mt19937_64 mt{std::random_device()()};
    int64_t operator()(int64_t mn, int64_t mx) { return std::uniform_int_distribution<int64_t>(mn, mx)(mt); }
} Rand;

void gencase() {
    cout << Rand(1, 100) << endl;
}
