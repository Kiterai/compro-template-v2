#include <algorithm>
#include <atcoder/convolution.hpp>
#include <atcoder/lazysegtree>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define repb(i, s, e) for (int i = s; i <= e; i++)
#define repi(i, f, n) for (int i = f; i < n; i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define bit(i) (1ll << i)

template <class T>
using vec = vector<T>;
using lint = long long;
constexpr int mod = 998244353;
template <class T>
T div2(T a, T b) { return (a + b - 1) / b; }

using mint = atcoder::modint998244353;
constexpr int infi = 1100100100;
constexpr lint inf = 1100100100100100100;

void solve() {
    int a;
    cin >> a;
    cout << a * 2 << endl;
}

int main() {
    // while (solve()) {}
    int c = 1;
    // cin >> c;
    for (int i = 0; i < c; i++) {
        solve();
    }
}
