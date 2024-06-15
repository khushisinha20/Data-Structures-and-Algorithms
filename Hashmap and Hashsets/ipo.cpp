//leetcode.com/problems/ipo/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> capitalAndProfits;
        int n = capital.size();

        for (int i = 0; i < n; ++i)
            capitalAndProfits.push_back({capital[i], profits[i]});

        sort(capitalAndProfits.begin(), capitalAndProfits.end());
        priority_queue<int> maxProfitHeap;
        int i = 0;

        while (k--) {
            while (i < n and capitalAndProfits[i].first <= w) {
                maxProfitHeap.push(capitalAndProfits[i].second);
                ++i;
            }

            if (maxProfitHeap.empty())
                break;

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
};
