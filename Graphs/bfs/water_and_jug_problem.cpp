//leetcode.com/problems/water-and-jug-problem/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int totalCapacity = jug1Capacity + jug2Capacity;
        vector<int> steps = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        
        queue<int> possibilities;
        possibilities.push(0);
        vector<bool> visited(totalCapacity, false);
        visited[0] = true;
        
        while (!possibilities.empty()) {
            int currentAmount = possibilities.front();
            possibilities.pop();
            
            if (currentAmount == targetCapacity)
                return true;
            
            for (int step: steps) {
                int newAmount = currentAmount + step;
                if (newAmount >= 0 and newAmount <= totalCapacity and !visited[newAmount]) {
                    possibilities.push(newAmount);
                    visited[newAmount] = true;
                }
            }
        }
        
        return false;
    }
};