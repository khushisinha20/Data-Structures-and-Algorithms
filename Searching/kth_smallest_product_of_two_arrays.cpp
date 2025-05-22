//leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool countLessEqual(vector<int>& nums1, vector<int>& nums2, long long mid, long long k) {
        long long count = 0;

        for (int num1 : nums1) {
            if (num1 < 0) {
                long long target = ceil(static_cast<double>(mid) / num1);
                int index = lower_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
                count += (nums2.size() - index);
            }
            else if (num1 > 0) {
                long long target = floor(static_cast<double>(mid) / num1);
                int index = upper_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
                count += index;
            }
            else {
                if (mid >= 0)
                    count += nums2.size();
            }

            if (count >= k) {
                return true;
            }
        }

        return count >= k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10;
        long long high = 1e10;
        long long answer = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid, k)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};

