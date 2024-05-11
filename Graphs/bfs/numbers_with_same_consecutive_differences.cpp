#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        queue<pair<int, int>> numbers;

        for (int i = 1; i <= 9; ++i)
            numbers.push({i, 1});

        while (!numbers.empty()) {
            int currentNumber = numbers.front().first;
            int currentLength = numbers.front().second;
            numbers.pop();

            if (currentLength == n) {
                result.push_back(currentNumber);
                continue;
            }

            int lastDigit = currentNumber % 10;
            int originalNumber = currentNumber;

            if (lastDigit + k < 10) {
                numbers.push({currentNumber * 10 + lastDigit + k, currentLength + 1});
            }

            if (lastDigit - k >= 0 and k != 0) {
                numbers.push({currentNumber * 10 + lastDigit - k, currentLength + 1});
            }
        }

        return result;
    }
};
