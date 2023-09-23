//leetcode.com/problems/minimum-operations-to-convert-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if (start == goal) return 0;

        queue<pair<long long, int>> possibilities;
        possibilities.push({start, 0});
        unordered_set<long long> visited;
        visited.insert(start);

        while (!possibilities.empty()) {
            long long currentValue = possibilities.front().first;
            int operations = possibilities.front().second;
            possibilities.pop();

            for (auto& num : nums) {
                long long nextValue;

                nextValue = currentValue + num;
                if (nextValue == goal) 
                    return operations + 1;
                if (nextValue >= 0LL && nextValue <= 1000LL && visited.find(nextValue) == visited.end()) {
                    possibilities.push({nextValue, operations + 1});
                    visited.insert(nextValue);
                }

                nextValue = currentValue - num;
                if (nextValue == goal) 
                    return operations + 1;
                if (nextValue >= 0LL && nextValue <= 1000LL && visited.find(nextValue) == visited.end()) {
                    possibilities.push({nextValue, operations + 1});
                    visited.insert(nextValue);
                }

                nextValue = currentValue ^ num;
                if (nextValue == goal) 
                    return operations + 1;
                if (nextValue >= 0LL && nextValue <= 1000LL && visited.find(nextValue) == visited.end()) {
                    possibilities.push({nextValue, operations + 1});
                    visited.insert(nextValue);
                }
            }
        }

        return -1;
    }
};
