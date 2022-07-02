//leetcode.com/problems/pancake-sorting/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIndexOfMax(int current_max, vector<int>& arr) {
        return find(arr.begin(), arr.end(), current_max) - arr.begin();
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int current_max = arr.size();
        while (current_max > 0) {
            int index_of_max = findIndexOfMax(current_max, arr);
            int max_value = arr[index_of_max];
            reverse(arr.begin(), arr.begin() + index_of_max + 1);
            res.push_back(index_of_max + 1);
            reverse(arr.begin(), arr.begin() + max_value);
            res.push_back(max_value);
            --current_max;
        }
        return res;
    }
};