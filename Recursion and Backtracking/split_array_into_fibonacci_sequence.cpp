//leetcode.com/problems/split-array-into-fibonacci-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(string& num, vector<int>& result, int index, long long f1, long long f2) {
        if (index == num.length() && result.size() > 2)
            return true;

        long long currentNum = 0;

        for (int i = index; i < num.length(); ++i) {
            if (i > index and num[index] == '0')
                break;

            currentNum = currentNum * 10 + (num[i] - '0');

            if (currentNum > numeric_limits<int>::max())
                break;

            if (result.size() < 2 || (long long)f1 + f2 == currentNum) {
                result.push_back(currentNum);
                if (backtrack(num, result, i + 1, f2, currentNum))
                    return true;
                result.pop_back();
            } else if ((long long)f1 + f2 < currentNum) {
                break;
            }
        }

        return false;
    }

    vector<int> splitIntoFibonacci(std::string num) {
        vector<int> result;
        backtrack(num, result, 0, 0, 0);
        return result;
    }
};
