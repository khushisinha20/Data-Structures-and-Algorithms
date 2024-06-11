//leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getOperations(vector<int>& nums1, vector<int>& nums2) {
        int operations = 0;
        int supposedMaxIn1 = nums1.back();
        int supposedMaxIn2 = nums2.back();
        int n = nums1.size();

        for (int i = 0; i < n - 1; ++i) {
            if (nums1[i] <= supposedMaxIn1 and nums2[i] <= supposedMaxIn2)
                continue;
            else if (nums2[i] <= supposedMaxIn1 and nums1[i] <= supposedMaxIn2)
                ++operations;
            else
                return -1;
        }

        return operations;
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int operationsBeforeSwappingLast = getOperations(nums1, nums2);
        swap(nums1[n - 1], nums2[n - 1]);
        int operationsAfterSwappingLast = getOperations(nums1, nums2);
        if (operationsBeforeSwappingLast == -1 and operationsAfterSwappingLast == -1)
            return -1;
        else if (operationsBeforeSwappingLast == -1 or operationsAfterSwappingLast == -1)
            return max(operationsBeforeSwappingLast, ++operationsAfterSwappingLast);
        else
            return min(operationsBeforeSwappingLast, ++operationsAfterSwappingLast);
    }
};
