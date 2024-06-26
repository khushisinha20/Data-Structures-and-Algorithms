//leetcode.com/problems/stock-price-fluctuation/

#include <bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    set<pair<int, int>> priceAndTimestampSet;
    pair<int, int> latest;
    map<int, int> timestampToPriceMap;
    int latestTimestamp;

    StockPrice() {
        latestTimestamp = 0;
    }

    void update(int timestamp, int price) {
        if (timestampToPriceMap.find(timestamp) != timestampToPriceMap.end()) {
            int previousPrice = timestampToPriceMap[timestamp];
            priceAndTimestampSet.erase({previousPrice, timestamp});
        }
        priceAndTimestampSet.insert({price, timestamp});
        timestampToPriceMap[timestamp] = price;

        if (timestamp >= latestTimestamp) {
            latestTimestamp = timestamp;
        }
    }

    int current() {
        return timestampToPriceMap[latestTimestamp];
    }

    int maximum() {
        return priceAndTimestampSet.rbegin() -> first;
    }

    int minimum() {
        return priceAndTimestampSet.begin() -> first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
