//leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;
        
        for (int i = 1; i < s.length(); ++i) {
            int leftEven = i - 1;
            int rightEven = i;
            
            while (leftEven >= 0 and rightEven < s.length() and s[leftEven] == s[rightEven]) {
                if (rightEven - leftEven + 1 > maxLength) {
                    maxLength = rightEven - leftEven + 1;
                    start = leftEven;
                }
                --leftEven;
                ++rightEven;
            }
            
            int leftOdd = i - 1;
            int rightOdd = i + 1;
            
            while (leftOdd >= 0 and rightOdd < s.length() and s[leftOdd] == s[rightOdd]) {
                if (rightOdd - leftOdd + 1 > maxLength) {
                    maxLength = rightOdd - leftOdd + 1;
                    start = leftOdd;
                }
                --leftOdd;
                ++rightOdd;
            }
        }
        
        return s.substr(start, maxLength);
    }
};