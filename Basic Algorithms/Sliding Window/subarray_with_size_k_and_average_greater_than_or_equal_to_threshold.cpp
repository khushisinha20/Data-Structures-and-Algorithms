//leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

#include <bits/stdc++.h>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int start = 0;
        int end = 0;
        int count_of_subarrays = 0;
        for (int end = 0; end < arr.size(); ++end) {
            sum += arr[end];
            if (end - start + 1 == k) {
                if ((sum / k) >= threshold)
                    ++count_of_subarrays;
                sum -= arr[start];
                ++start;     
            }
        }
        return count_of_subarrays;
    }
};