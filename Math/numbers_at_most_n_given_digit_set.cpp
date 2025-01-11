//leetcode.com/problems/numbers-at-most-n-given-digit-set/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string nStr = to_string(n);
        int result = 0;
        int thresholdDigitCount = nStr.length();
        int digitSize = digits.size();

        for (int i = 1; i < thresholdDigitCount; ++i) {
            result += (int)pow(digitSize, i);
        }

        for (int i = 0; i < thresholdDigitCount; ++i) {
            bool hasSameDigit = false;
            for (auto& digit : digits) {
                if (digit[0] < nStr[i]) {
                    result += (int)pow(digitSize, thresholdDigitCount - i - 1);
                } else if (digit[0] == nStr[i]) {
                    hasSameDigit = true;
                } else {
                    break;
                }
            }
            if (!hasSameDigit) {
                return result;
            }
        }

        return result + 1;
    }
};

