//leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size(), 0);
        stack<int> s;
        for (int i = prices.size() - 1; i >= 0; --i) {
            if (s.empty())
                res[i] = prices[i];
            else if (!s.empty() && s.top() <= prices[i])
                res[i] = prices[i] - s.top();
            else if (!s.empty() && s.top() > prices[i]) {
                while (!s.empty() && s.top() > prices[i])
                    s.pop();
                if (s.empty())
                    res[i] = prices[i];
                else
                    res[i] = prices[i] - s.top();
            }
            s.push(prices[i]);
        }
        return res;
    }
};class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size(), 0);
        stack<int> s;
        for (int i = prices.size() - 1; i >= 0; --i) {
            if (s.empty())
                res[i] = prices[i];
            else if (!s.empty() && s.top() <= prices[i])
                res[i] = prices[i] - s.top();
            else if (!s.empty() && s.top() > prices[i]) {
                while (!s.empty() && s.top() > prices[i])
                    s.pop();
                if (s.empty())
                    res[i] = prices[i];
                else
                    res[i] = prices[i] - s.top();
            }
            s.push(prices[i]);
        }
        return res;
    }
};