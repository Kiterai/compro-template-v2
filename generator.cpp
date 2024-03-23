#include <iostream>
#include "tools/rand.hpp"
using namespace std;

Rand_t Rand;
#define RandN(n, mn, mx) int n = Rand(mn, mx)

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, ini, n) for (int i = (ini); i < (n); i++)

int casen() { return 100; }

void gencase(int _case) {
    RandN(n, 1, 10);
    RandN(m, 1, 10);
    cout << n << ' ' << m << endl;
    auto a = Rand.perm(n * m);
    rep(i, n * m) cout << a[i] << ' ';
}
