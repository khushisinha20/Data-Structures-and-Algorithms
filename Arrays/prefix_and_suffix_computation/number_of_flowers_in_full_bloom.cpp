#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> prefixSum;
        
        for (auto& person: persons)
            prefixSum[person] = 0;
        
        for (auto& flower: flowers) {
            int start = flower[0];
            int end = flower[1] + 1;
            ++prefixSum[start];
            --prefixSum[end];
        }
        
        int currentSum = 0;
        for (auto& pair: prefixSum) {
            currentSum += pair.second;
            prefixSum[pair.first] = currentSum;
        }
        
        vector<int> ans(persons.size(), 0);
        
        for (int i = 0; i < persons.size(); ++i)
            ans[i] = prefixSum[persons[i]]; 
        
        return ans;
    }
};