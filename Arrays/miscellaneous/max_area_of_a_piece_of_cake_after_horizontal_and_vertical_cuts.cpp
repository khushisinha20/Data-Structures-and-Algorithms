//leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int max_vertical_cut = max(verticalCuts[0], w - verticalCuts.back());
        int max_horizontal_cut = max(horizontalCuts[0], h - horizontalCuts.back());;
        for (int i = 1; i < horizontalCuts.size(); ++i) 
            max_horizontal_cut = max(max_horizontal_cut, (horizontalCuts[i] - horizontalCuts[i - 1]));
        for (int i = 1; i < verticalCuts.size(); ++i) 
            max_vertical_cut = max(max_vertical_cut, verticalCuts[i] - verticalCuts[i - 1]);
        long long mod = 1000000007;
        return (long long) ((long long) (max_horizontal_cut) * (long long) (max_vertical_cut)) % mod;
    }
};