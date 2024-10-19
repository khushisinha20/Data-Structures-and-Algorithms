//leetcode.com/problems/largest-multiple-of-three/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool removeDigit(vector<int>& digits, int remainder) {
        for (auto it = digits.begin(); it != digits.end(); ++it) {
            if (*it % 3 == remainder) {
                digits.erase(it);
                return true;
            }
        }

        return false;
    }

    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int sum = accumulate(digits.begin(), digits.end(), 0);

        if (sum % 3 == 1) {
            if (!removeDigit(digits, 1)) {
                removeDigit(digits, 2);
                removeDigit(digits, 2);
            }
        } else if (sum % 3 == 2) {
            if (!removeDigit(digits, 2)) {
                removeDigit(digits, 1);
                removeDigit(digits, 1);
            }
        }

        reverse(digits.begin(), digits.end());
        string result;
        for (int digit: digits)
            result += to_string(digit);

        if (result.empty())
            return "";

        if (result.front() == '0')
            return "0";

        return result;
    }
};
