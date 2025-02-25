//leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void xform(vector<int>& arr) {
        for (auto& num: arr)
            num = num % 2;
    }

    int numOfSubarrays(vector<int>& arr) {
        int start = 0;
        const int MOD = 1e9 + 7;

        xform(arr);
        int sum = 0;
        int oddCount = 0;
        int evenCount = 1; // an empty prefix sum is considered even
        int ans = 0;

        for (int end = 0; end < arr.size(); ++end) {
            sum += arr[end];
            if (sum % 2) {
                ans = (ans + evenCount) % MOD;
                ++oddCount;
            } else {
                ans = (ans + oddCount) % MOD;
                ++evenCount;
            }
        }

        return ans;
    }
};
