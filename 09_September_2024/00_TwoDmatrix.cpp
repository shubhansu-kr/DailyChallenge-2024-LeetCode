// https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01

#include <bits/stdc++.h>
using namespace std ;

static const auto _ = []() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

constexpr auto get_iota = [](){
    int const N = 4 * 10'000 + 1;
    std::array<int, N> iota{};
    for (int i = 0; i != N; ++i) {
        iota[i] = i;
    }
    return iota;
}();

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) const {
        int const k {static_cast<int>(original.size())};
        if (n * m != k) return {};
        
        std::vector<int> offset_row(m, 0);
        std::memcpy(offset_row.data(), get_iota.data(), m * sizeof(int));

        vector<vector<int>> res (m, std::vector(n, 0));
        std::for_each(offset_row.begin(), offset_row.end(), [&](int row){
            int const offset_original {row * n};
            unsigned long const bytes_row {n * sizeof(int)};
            std::memcpy(res[row].data(), original.data() + offset_original, bytes_row);
        });

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    return 0;
}