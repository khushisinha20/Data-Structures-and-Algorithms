//practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    char maxDigit(string& str, int index) {
        char max_digit = '0';
        for (int i = index; i < str.length(); ++i) {
            if (str[i] > max_digit)
                max_digit = str[i];
        }
        return max_digit;
    }
    
    void maximumNum(string& s, string& res, int k, int n, int index) {
        if (k == 0 || index == n)
            return;
        
        char max_digit = maxDigit(s, index);
        if (max_digit != s[index])
            --k;
    
        for (int i = n - 1; i >= index; --i) {
            if (s[i] == max_digit) {
                swap(s[index], s[i]);
                res = max(s, res);
                maximumNum(s, res, k, n, index + 1);
                swap(s[index], s[i]);
            }
        }
    }
    
    string findMaximumNum(string str, int k) {
       string res = str;
       int n = str.length();
       int index = 0;
       maximumNum(str, res, k, n, 0);
       return res;
    }
};
