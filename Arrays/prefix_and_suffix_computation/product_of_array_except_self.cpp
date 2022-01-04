#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output_arr;
        output_arr.push_back(1);
        for (int i = 1; i < nums.size(); ++i) {
            output_arr.push_back(output_arr[i - 1] * nums[i - 1]);
        }
        int R = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            output_arr[i] = output_arr[i] * R;
            R *= nums[i];
        }
        return output_arr;
    }   
};