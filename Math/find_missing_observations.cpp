// leetcode.com/problems/find-missing-observations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int nTotal = (mean * (n + m)) - accumulate(rolls.begin(), rolls.end(), 0);
        
        if (nTotal < n or nTotal > n * 6)
            return {};
        
        vector<int> result;
        
        while (n > 0) {
            int dice = min(nTotal - (n - 1), 6);
            result.push_back(dice);
            nTotal -= dice;
            --n;
        }
        
        return result;
    }
};
