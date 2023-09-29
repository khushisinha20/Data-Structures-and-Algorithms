//leetcode.com/problems/find-good-days-to-rob-the-bank/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        for (int i = 1; i < n; ++i)
            if (security[i] <= security[i - 1])
                left[i] = left[i - 1] + 1;
        
        for (int i = n - 2; i >= 0; --i)
            if (security[i] <= security[i + 1])
                right[i] = right[i + 1] + 1;
        
        vector<int> ans;
        for (int i = time; i < n - time; ++i)
            if (min(left[i], right[i]) >= time)
                ans.push_back(i);
        
        return ans;
    }
};