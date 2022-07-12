//leetcode.com/problems/matchsticks-to-square/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& sides, vector<int>& matchsticks, int index, int side_length) {
        if (index == matchsticks.size())
            return true;
        
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] <= side_length) {
                sides[i] += matchsticks[index];
                if (backtrack(sides, matchsticks, index + 1, side_length))
                    return true;
                sides[i] -= matchsticks[index];
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        long long perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (perimeter % 4)
            return false;
        
        vector<int> sides(4, 0);
        int side_length = perimeter / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return backtrack(sides, matchsticks, 0, side_length);
    }
};