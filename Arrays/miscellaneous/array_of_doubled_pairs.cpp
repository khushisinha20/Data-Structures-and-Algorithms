//leetcode.com/problems/array-of-doubled-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (auto num: arr) {
            ++freq[num];
        }
        sort(arr.begin(), arr.end());
        for (auto num: arr) {
            if (freq[num] && freq[2 * num]) {
                --freq[num];
                --freq[2 * num];
            }
        }
        for (auto i: freq) {
            if (i.second > 0)
                return false;
        }
        return true;
    }
};