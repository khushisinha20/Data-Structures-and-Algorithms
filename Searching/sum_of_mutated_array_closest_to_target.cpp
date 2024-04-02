//leetcode.com/problems/sum-of-mutated-array-closest-to-target/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getUpdatedSum(vector<int>& arr, int value) {
        int sum = 0;
        for (int element: arr)
            sum += min(element, value);
        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int low = 0;
        int high = arr.back();
        int ans = -1;
        int minDiff = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = getUpdatedSum(arr, mid);
            if (sum <= target) {
                if (target - sum < minDiff) {
                    minDiff = target - sum;
                    ans = mid;
                }
                low = mid + 1;
            } else
                high = mid - 1;
        }

        if (abs(target - getUpdatedSum(arr, ans + 1)) < minDiff)
            ++ans;
        return ans;
    }
};
