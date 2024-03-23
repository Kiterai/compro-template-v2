#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

struct Rand_t {
    std::mt19937_64 mt{std::random_device()()};
    int64_t operator()(int64_t mn, int64_t mx) { return std::uniform_int_distribution<int64_t>(mn, mx)(mt); }
    std::vector<int> perm(int len, int v = 1) {
        std::vector<int> a(len);
        std::iota(a.begin(), a.end(), v);
        std::shuffle(a.begin(), a.end(), mt);
        return a;
    }
};
