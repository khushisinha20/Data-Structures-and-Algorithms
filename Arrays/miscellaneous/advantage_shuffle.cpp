//leetcode.com/problems/advantage-shuffle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> nums1Set(nums1.begin(), nums1.end());
        int n = nums1.size();
        vector<int> result(n, -1);
        int j = -1;

        for (int i = 0; i < n; ++i) {
            ++j;
            auto justGreater = nums1Set.upper_bound(nums2[i]);
            if (justGreater == nums1Set.end())
                continue;
            result[j] = *justGreater;
            nums1Set.erase(justGreater);
        }

        for (int i = 0; i < n; ++i) {
            if (result[i] == -1) {
                result[i] = *nums1Set.begin();
                nums1Set.erase(nums1Set.begin());
            }
        }

        return result;
    }
};
