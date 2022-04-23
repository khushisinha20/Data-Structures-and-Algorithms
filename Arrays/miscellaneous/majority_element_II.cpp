//leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        int count_of_num1 = 0;
        int count_of_num2 = 0;
        for (auto element: nums) {
            if (element  == num1)
                ++count_of_num1;
            else if (element == num2)
                ++count_of_num2;
            else if (count_of_num1 == 0) {
                num1 = element;
                count_of_num1 = 1;
            } else if (count_of_num2 == 0) {
                num2 = element;
                count_of_num2 = 1;
            } else {
                --count_of_num1;
                --count_of_num2;
            }
        }
        vector<int> res;
        int freq_of_num1 = 0;
        int freq_of_num2 = 0;
        for (auto element: nums) {
            if (element == num1)
                ++freq_of_num1;
            if (element == num2)
                ++freq_of_num2;
        }
        if (freq_of_num1 > nums.size() / 3)
            res.push_back(num1);
        if (freq_of_num2 > nums.size() / 3)
            res.push_back(num2);
        return res;
    }
};