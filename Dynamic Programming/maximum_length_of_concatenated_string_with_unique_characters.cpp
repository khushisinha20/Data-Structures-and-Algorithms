//leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCommon(string& a, string& b) {
        vector<int> frequency(26, 0);
        for (int i = 0; i < a.length(); ++i) {
            if (frequency[a[i] - 'a'] > 0)
                return true;
            ++frequency[a[i] - 'a'];
        }
        
        for (int i = 0; i < b.length(); ++i)
            if (frequency[b[i] - 'a'] > 0)
                return true;
        
        return false;
    }
    
    int helper(int index, vector<string>& arr, string current) {
        if (index >= arr.size())
            return current.length();
        
        int include = 0;
        int exclude = 0;
        
        if (hasCommon(arr[index], current))
            exclude = helper(index + 1, arr, current);
        else {
            exclude = helper(index + 1, arr, current);
            include = helper(index + 1, arr, current + arr[index]);
        }
        
        return max(exclude, include);
    }
    
    int maxLength(vector<string>& arr) {
        string current = "";
        return helper(0, arr, current);
    }
};