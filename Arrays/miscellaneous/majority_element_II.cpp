//leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        
        for (auto num: nums) {
            if (num == num1)
                ++count1;
            else if (num == num2)
                ++count2;
            else if (count1 == 0) {
                num1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                num2 = num;
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }
        
        vector<int> majority;
        count1 = 0;
        count2 = 0;
        
        for (auto num: nums) {
            if (num == num1)
                ++count1;
            if (num == num2)
                ++count2;
        }
        
        if (count1 > nums.size() / 3)
             majority.push_back(num1);
        
        if (count2 > nums.size() / 3)
             majority.push_back(num2);
        
        return majority;
    }
};