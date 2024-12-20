//leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLNDS(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis;

        for (int num: arr) {
            auto it = upper_bound(lis.begin(), lis.end(), num);
            if (it == lis.end())
                lis.push_back(num);
            else
                *it = num;
        }

        return lis.size();
    }

    int kIncreasing(vector<int>& arr, int k) {
        int result = 0;
        int n = arr.size();

        for (int i = 0; i < k; ++i) {
            vector<int> subsequence;
            for (int j = i; j < n; j += k) {
                subsequence.push_back(arr[j]);
            }
            result += subsequence.size() - lengthOfLNDS(subsequence);
        }

        return result;
    }
};
