//leetcode.com/problems/ipo/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int availableCapital = w;
        priority_queue<pair<int, int>> maxProfitHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap;
        for (int i = 0; i < capital.size(); ++i)
            minCapitalHeap.push({capital[i], profits[i]});
        
        for (int i = 0; i < k; ++i) {
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
                maxProfitHeap.push({minCapitalHeap.top().second, minCapitalHeap.top().first});
                minCapitalHeap.pop();
            }
            
            if (maxProfitHeap.empty())
                break;
            
            availableCapital += maxProfitHeap.top().first;
            maxProfitHeap.pop();
        }
        return availableCapital;
    }
};