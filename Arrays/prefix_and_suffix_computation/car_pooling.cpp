/*leetcode.com/problems/car-pooling*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> total_passengers(1002, 0);
        for (int i = 0; i < trips.size(); ++i) {
            int number_of_passengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            total_passengers[from] += number_of_passengers;
            total_passengers[to] -= number_of_passengers;
        }
        for (int i = 1; i < 1002; ++i) {
            total_passengers[i] += total_passengers[i - 1];
        }
        for (int i = 0; i < 1002; ++i) {
            if (total_passengers[i] > capacity)
                return false;
        }
        return true;
    }
};