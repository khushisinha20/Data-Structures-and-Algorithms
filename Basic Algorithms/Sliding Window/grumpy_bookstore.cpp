//leetcode.com/problems/grumpy-bookstore-owner

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int start = 0;
        int non_grumpy_sum = 0;
        int max_satisfied_customers = 0;
        for (int i = 0; i < grumpy.size(); ++i)
            if (grumpy[i] == 0)
                non_grumpy_sum += customers[i];
        for (int end = 0; end < grumpy.size(); ++end) {
            if (grumpy[end] == 1)
                non_grumpy_sum += customers[end];
            if (end - start + 1 == minutes) {
                max_satisfied_customers = max(max_satisfied_customers, non_grumpy_sum);
                if (grumpy[start] == 1)
                    non_grumpy_sum -= customers[start];
                ++start;
            }
        }
        return max_satisfied_customers;
    }
};