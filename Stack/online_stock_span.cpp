//leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> stock;
    int index = -1;
    int span = -1; 
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        ++index;
        
        if (stock.empty())
            span = 1 + index;
        
        if (!stock.empty() && stock.top().first > price)
            span = index - stock.top().second;
        else {
            while(!stock.empty() && stock.top().first <= price)
                stock.pop();
            if (stock.empty())
                span = 1 + index;
            else
                span = index - stock.top().second;
        }
        
        stock.push({price, index});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */