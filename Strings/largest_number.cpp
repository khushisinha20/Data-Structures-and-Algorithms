//leetcode.com/problems/largest-number/

#include <bits/stdc++.h>
using namespace std;

bool comparator(string& a, string& b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        for (auto num: nums)
            numbers.push_back(to_string(num));
        sort(numbers.begin(), numbers.end(), comparator);
        string res = "";
        for (auto num: numbers)
            res += num;
        if (res[0] == '0')
            return "0";
        return res;
    }
};