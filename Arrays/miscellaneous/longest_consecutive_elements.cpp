//leetcode.com/problems/longest-consecutive-sequence/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int longest_consective_elements = 1;
        unordered_map<int, bool> record;
        for (int i = 0; i < nums.size(); ++i) {
            record[nums[i]] = true;
        }
        for (auto num: nums) {
            if (record.find(num - 1) != record.end()) {
                record[num] = false;
            }
        }
        for (auto num: nums) {
            if (record[num]) {
                int temp_length = 1;
                while (record.find(num + 1) != record.end()) {
                    ++temp_length;
                    ++num;
                }
                longest_consective_elements = max(longest_consective_elements, temp_length);
            }
        }
        return longest_consective_elements;
    }
};