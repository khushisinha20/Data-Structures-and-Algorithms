//leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s;
    int index = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ++index;
        int res;
        if (s.empty())
            res = index + 1;
        else if (!s.empty() && s.top().first > price)
            res = index - s.top().second;
        else if (!s.empty() && s.top().first <= price) {
            while (!s.empty() && s.top().first <= price)
                s.pop();
            if (s.empty())
                res = index + 1;
            else
                res = index - s.top().second;
        }
        s.push({price, index});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */