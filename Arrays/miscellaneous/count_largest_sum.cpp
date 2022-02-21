//leetcode.com/problems/count-largest-group/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        vector<int> groups(37, 0);
        for (int i = 1; i <= n; ++i) {
            ++groups[digitSum(i)];
        }
        int max_size = *max_element(groups.begin(), groups.end());
        return count(groups.begin(), groups.end(), max_size);
    }
};