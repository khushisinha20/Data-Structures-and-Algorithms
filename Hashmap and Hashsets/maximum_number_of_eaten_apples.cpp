//leetcode.com/problems/maximum-number-of-eaten-apples/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int, int> dayToRotCount;
        int n = apples.size();
        int ans = 0;

        int maxDays = 0;
        for (int i = 0; i < apples.size(); ++i)
            maxDays = max(maxDays, i + days[i]);

        for (int i = 0; i <= maxDays; ++i) {
            while (!dayToRotCount.empty() and (dayToRotCount.begin() -> first <= i or dayToRotCount.begin() -> second == 0))
                dayToRotCount.erase(dayToRotCount.begin());
            if (i < n and apples[i] > 0)
                dayToRotCount[i + days[i]] += apples[i];
            if (!dayToRotCount.empty() and dayToRotCount.begin() -> second > 0) {
                --dayToRotCount.begin() -> second;
                ++ans;
            }
            if (i > n and dayToRotCount.empty())
                break;
        }

        return ans;
    }
};
