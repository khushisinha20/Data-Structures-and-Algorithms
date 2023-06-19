#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/24-game/

class Solution {
public:
    float DIFF_TOLERANT = 0.1;

    vector<double> performOperations(double& a, double& b) {
        return {a + b, a - b, b - a, a * b, a / b, b / a};
    }

    vector<double> toDouble(vector<int>& cards) {
        vector<double> nums;
        for (auto& card: cards)
            nums.push_back((double)card);
        return nums;
    }

    bool judgePoint24Util(vector<double>& nums) {
        if (nums.size() == 1)
            return abs(nums[0] - 24) <= DIFF_TOLERANT;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                double firstOperand = nums[i];
                double secondOperand = nums[j];
                vector<double> operationResults = performOperations(firstOperand, secondOperand);

                vector<double> copyNums = nums;
                copyNums.erase(copyNums.begin() + i);
                copyNums.erase(copyNums.begin() + j);

                for (auto& operationResult: operationResults) {
                    copyNums.push_back(operationResult);
                    if (judgePoint24Util(copyNums))
                        return true;
                    copyNums.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        auto nums = toDouble(cards);
        return judgePoint24Util(nums);
    }
};
