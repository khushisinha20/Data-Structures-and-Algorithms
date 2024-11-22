//leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> getOddValues(vector<int>& nums) {
        vector<long long> oddValues;
        for (int& num: nums)
            if (num % 2 == 1)
                oddValues.push_back(num);
        sort(oddValues.begin(), oddValues.end());
        return oddValues;
    }

    vector<long long> getEvenValues(vector<int>& nums) {
        vector<long long> evenValues;
        for (int& num: nums)
            if (num % 2 == 0)
                evenValues.push_back(num);
        sort(evenValues.begin(), evenValues.end());
        return evenValues;
    }

    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<long long> oddNums = getOddValues(nums);
        vector<long long> evenNums = getEvenValues(nums);
        vector<long long> oddTarget = getOddValues(target);
        vector<long long> evenTarget = getEvenValues(target);

        long long ans = 0;
        for (int i = 0; i < oddNums.size(); ++i) {
            if (oddTarget[i] > oddNums[i])
                ans += (oddTarget[i] - oddNums[i]);
        }

        for (int i = 0; i < evenNums.size(); ++i) {
            if (evenTarget[i] > evenNums[i])
                ans += (evenTarget[i] - evenNums[i]);
        }

        return ans / 2;
    }
};
