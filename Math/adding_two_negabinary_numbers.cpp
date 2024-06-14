//leetcode.com/problems/adding-two-negabinary-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int size = max(arr1.size(), arr2.size()) + 2;
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        int digitFrom1 = 0;
        int digitFrom2 = 0;
        int i = 0;
        int carry = 0;
        int remainder = 0;

        while (i < size) {
            int digitFrom1 = i < arr1.size() ? arr1[i] : 0;
            int digitFrom2 = i < arr2.size() ? arr2[i] : 0;
            int sum = digitFrom1 + digitFrom2 + carry;
            remainder = sum % (-2);
            carry = sum / (-2);
            if (remainder < 0) {
                remainder += 2;
                ++carry;
            }
            ans.push_back(remainder);
            ++i;
        }

        while (ans.back() == 0 and ans.size() > 1)
            ans.pop_back();

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
