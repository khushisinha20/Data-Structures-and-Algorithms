//leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfDigitSquares(int n) {
        int digit_square_sum = 0;
        while (n) {
            digit_square_sum += ((n % 10) * (n % 10));
            n /= 10;
        }
        return digit_square_sum;
    }
    
    bool isHappy(int n) {
        while (true) {
            if (sumOfDigitSquares(n) == 1)
                return true;
            if (sumOfDigitSquares(n) == 89)
                return false;
            n = sumOfDigitSquares(n);
        }
    }
};