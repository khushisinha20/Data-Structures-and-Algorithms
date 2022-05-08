//leetcode.com/problems/sum-of-all-odd-length-subarrays/

#include <bits/stdc++.h>
using namespace std;
//leetcode.com/problems/sum-of-all-odd-length-subarrays/discuss/854304/C%2B%2B-O(N)-Single-Line-Logic

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        int contribution = 0;
        for (int i = 0; i < arr.size(); ++i) {
            contribution = ceil((arr.size() - i) * (i + 1) / 2.0);
            res += arr[i] * contribution;
        }
        return res;
    }
};