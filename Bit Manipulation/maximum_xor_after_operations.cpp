//leetcode.com/problems/maximum-xor-after-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int OR = 0;
        for (auto& num: nums)
            OR |= num;

        return OR;
    }
};
