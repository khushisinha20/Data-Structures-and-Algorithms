//leetcode.com/problems/additive-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfAdditive(string& str, int i, int n, vector<long long>& ans) {
        if (i == n && ans.size() > 2)
            return true;
        
        unsigned long long num = 0; 
        
        for (int j = i; j < n; ++j) {
            num = num * (long long) 10 + (long long) (str[j] - '0');
            if (num > LLONG_MAX)
                return false;
            
            if (str[i] == '0' && i < j)
                return false;
            
            if (ans.size() < 2 || ans.back() + ans[ans.size() - 2] == num) {
                ans.push_back(num);
                if (checkIfAdditive(str, j + 1, n, ans))
                    return true;
                ans.pop_back();
            }
        }
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        int n = num.size();
        vector<long long> ans;
        return checkIfAdditive(num, 0, n, ans);
    }
};