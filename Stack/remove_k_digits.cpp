//leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> digitStack;
        
        for (auto& currentDigit : num) {
            while (!digitStack.empty() and k > 0 and digitStack.back() > currentDigit) {
                digitStack.pop_back();
                --k;
            }
            
            if (!digitStack.empty() or currentDigit != '0')
                digitStack.push_back(currentDigit);
        }
        
        while (k-- and !digitStack.empty())
            digitStack.pop_back();
        
        string result;
        
        if (digitStack.empty())
            return "0";
        
        for (auto& digit: digitStack)
            result += digit;
        
        return result;
    }
};