//leetcode.com/problems/plus-one/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (true) {
            if (digits[i] == 9) {
                digits[i] = 0;
                --i;
                if (i < 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            } else {
                ++digits[i];
                break;
            }
        }
        return digits;
    }
};