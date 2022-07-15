//leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int low = 0;
        int high = n1;
        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = ((n1 + n2) / 2) - cut1;
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            if (l1 > r2)
                high = cut1 - 1;
            else if (l2 > r1)
                low = cut1 + 1;
            else {
                if ((n1 + n2) % 2 == 0)
                    return ((double) max(l1, l2) + (double) min(r1, r2)) / 2;
                return (double) min(r1, r2);
            }
        }
        return 0;
    }
};