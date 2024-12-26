//leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        });

        map<int, int> categoryCount;
        long long totalElegance = 0;

        for (int i = 0; i < k; ++i) {
            totalElegance += items[i][0];
            ++categoryCount[items[i][1]];
        }

        long long categories = categoryCount.size();
        totalElegance += categories * categories;
        long long maxElegance = totalElegance;
        int j = k - 1;

        for (int i = k; i < items.size(); ++i) {
            if (categoryCount.find(items[i][1]) == categoryCount.end()) {
                while (j >= 0 and categoryCount[items[j][1]] < 2)
                    --j;
                if (j < 0)
                    break;
                --categoryCount[items[j][1]];
                ++categoryCount[items[i][1]];
                totalElegance -= items[j][0];
                totalElegance += items[i][0];
                totalElegance -= categories * categories;
                ++categories;
                totalElegance += categories * categories;
                --j;
                maxElegance = max(maxElegance, totalElegance);
            }
        }

        return maxElegance;
    }
};
