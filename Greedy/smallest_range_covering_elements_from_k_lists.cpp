//leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool comparator(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    
    vector<vector<int>> flattenList(vector<vector<int>>& nums) {
        vector<vector<int>> flatList;
        
        for (int row = 0; row < nums.size(); ++row) 
            for (int col = 0; col < nums[row].size(); ++col)  
                flatList.push_back({row, nums[row][col]});
        
        return flatList;
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>> flatList = flattenList(nums);
        sort(flatList.begin(), flatList.end(), [this](const vector<int>& a, const vector<int>& b) {
            return comparator(a, b);
        });
        
        unordered_map<int, int> frequencyMap;
        int start = 0;
        int k = nums.size();
        int minLength = INT_MAX;
        vector<int> result;
        
        for (int end = 0; end < flatList.size(); ++end) { 
            ++frequencyMap[flatList[end][0]];
            
            while (frequencyMap.size() == k) {
                int currentLength = flatList[end][1] - flatList[start][1];  
                if (currentLength < minLength) {
                    minLength = currentLength;
                    result = {flatList[start][1], flatList[end][1]};  
                }
                
                --frequencyMap[flatList[start][0]];
                
                if (frequencyMap[flatList[start][0]] == 0)
                    frequencyMap.erase(flatList[start][0]);
                
                ++start;
            }
        }
        
        return result;
    }
};
