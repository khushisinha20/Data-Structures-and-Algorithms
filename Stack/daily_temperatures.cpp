//leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        stack<pair<int, int>> s;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            if (s.empty())
                res.push_back(0);
            else if (!s.empty() && s.top().first > temperatures[i])
                res.push_back(s.top().second - i);
            else {
                while (!s.empty() && s.top().first <= temperatures[i])
                    s.pop();
                if (s.empty())
                    res.push_back(0);
                else
                    res.push_back(s.top().second - i);
            }
            s.push({temperatures[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};