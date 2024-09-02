//leetcode.com/problems/number-of-digit-one/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        long long factor = 1;

        while (n / factor > 0) {
            int lower = n - (n / factor) * factor;
            int currentDigit = (n / factor) % 10;
            int higher = n / (factor * 10);

            if (currentDigit == 0)
                count += higher * factor;
            else if (currentDigit == 1)
                count += high//leetcode.com/problems/number-of-digit-one/er * factor + lower + 1;
            else
                count += (higher + 1) * factor;

            factor *= 10;
        }

        return count;
    }
};
