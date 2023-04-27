//leetcode.com/problems/basic-calculator/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        
        int number = 0;
        int result = 0;
        int sign = 1;
        
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) 
                number = number * 10 + (s[i] - '0');
            else if (s[i] == '+') {
                result += (sign * number);
                number = 0;
                sign = 1;
            } else if (s[i] == '-') {
                result += (sign * number);
                number = 0;
                sign = -1;
            } else if (s[i] == '(') {
                nums.push(result);
                nums.push(sign);
                number = 0;
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result += (sign * number);
                number = 0;
                
                int previousSign = nums.top();
                nums.pop();
                
                int previousResult = nums.top();
                nums.pop();
                
                result *= previousSign;
                result += previousResult;
            }
        }
        
        result += (number * sign);
        return result;
    }
};
