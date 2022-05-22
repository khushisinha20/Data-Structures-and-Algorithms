//leetcode.com/problems/find-palindrome-with-fixed-length/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getPalindrome(int n, int k) {
        if (n <= 9 && k == 1)
            return n;
        
        if (9 * pow(10, (k - 1) / 2) < n)
            return -1;
        
        long long halfNum = (n - 1) + pow(10, (k - 1) / 2);
        long long num = halfNum;
        
        if (k & 1)
            halfNum /= 10;
        
        while (halfNum) {
            num = num * 10 + halfNum % 10;
            halfNum /= 10;
        }
        
        return num;    
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res;
        for (auto query: queries) {
            res.push_back(getPalindrome(query, intLength));
        }
        return res;
    }
};