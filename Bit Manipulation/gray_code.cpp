//leetcode.com/problems/gray-code/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(bitset<32>& bits, vector<int>& result, int k) {
        if (k == 0)
            result.push_back(bits.to_ulong());
        else {
            helper(bits, result, k - 1);
            bits.flip(k - 1);
            helper(bits, result, k - 1);
        }
    }
    
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        helper(bits, result, n);
        return result;
    }
};