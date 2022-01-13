//leetcode.com/problems/k-concatenation-maximum-sum/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m = 1000000007;
    long long kadanesAlgorithm(vector<int>& a) {
        int current_sum = a[0];
        int overall_sum = a[0];
        for (int i = 1; i < a.size(); ++i) {
            if (current_sum >= 0) {
                current_sum += a[i];
            } else {
                current_sum = a[i];
            }
            if (current_sum > overall_sum)
                overall_sum = current_sum;
        }
        if (overall_sum < 0)
            return 0;
        return overall_sum;
    }
    
    long long kadanesAlgorithmTwoArrays(vector<int>& a) {
        vector<int> v;
        for (int i = 0; i < a.size(); ++i)
            v.push_back(a[i]);
        for (int i = 0; i < a.size(); ++i) {
            v.push_back(a[i]);
        }
        return kadanesAlgorithm(v);
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0;
        for (int i = 0; i < arr.size(); ++i)
            sum += arr[i];
        if (k == 1) {
            return kadanesAlgorithm(arr) % m;
        } else if (sum < 0) {
            return kadanesAlgorithmTwoArrays(arr) % m;
        } else {
            return (kadanesAlgorithmTwoArrays(arr) + (((k - 2) * sum)) % m) % m; 
        }
    }
};