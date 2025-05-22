//leetcode.com/problems/avoid-flood-in-the-city/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> availableDryDays;
        unordered_map<int, int> lakeLastRained;
        vector<int> result(n, 1);

        for (int day = 0; day < n; ++day) {
            int lake = rains[day];

            if (lake > 0) {
                if (lakeLastRained.count(lake)) {
                    auto it = availableDryDays.upper_bound(lakeLastRained[lake]);
                    if (it == availableDryDays.end()) {
                        return {};
                    }
                    result[*it] = lake;
                    availableDryDays.erase(it);
                }
                result[day] = -1;
                lakeLastRained[lake] = day;
            } else {
                availableDryDays.insert(day);
            }
        }

        return result;
    }
};

