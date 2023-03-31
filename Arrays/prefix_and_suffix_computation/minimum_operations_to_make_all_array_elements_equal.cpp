//leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> getPrefixSum(vector<int>& nums) {
        vector<long long> prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) 
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        return prefixSum;
    }
    
    long long minOperationsLeftOfPivot(vector<long long>& prefixSum, long long& pivot, int& query) {
        if (pivot == -1)
            return 0;
        return abs(query * (pivot + 1) - prefixSum[pivot]);
    }
    
    long long minOperationsRightOfPivot(vector<long long>& prefixSum, long long& pivot, int& query) {
        long long n = prefixSum.size();
        if (pivot == -1)
            return prefixSum.back() - query * n;
        return (prefixSum.back() - prefixSum[pivot]) - (query * (n - pivot - 1));
    }
    
    long long minOperationsToMakeEqual(vector<int>& nums, vector<long long>& prefixSum, int& query) {
        long long pivot = upper_bound(nums.begin(), nums.end(), query) - nums.begin();
        --pivot;
        long long leftOperations = minOperationsLeftOfPivot(prefixSum, pivot, query);
        long long rightOperations = minOperationsRightOfPivot(prefixSum, pivot, query);
        return leftOperations + rightOperations;
    }
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum = getPrefixSum(nums);
        vector<long long> result;
        
        for (auto& query: queries) 
            result.push_back(minOperationsToMakeEqual(nums, prefixSum, query));
        
        return result;
    }
};