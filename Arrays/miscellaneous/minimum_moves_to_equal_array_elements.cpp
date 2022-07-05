//leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        int min_num = *min_element(nums.begin(), nums.end());
        return sum - nums.size() * min_num; 
    }
};