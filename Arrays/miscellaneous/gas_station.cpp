//leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_amount_of_gas = 0;
        int total_cost = 0;
        total_amount_of_gas = accumulate(gas.begin(), gas.end(), total_amount_of_gas);
        total_cost = accumulate(cost.begin(), cost.end(), total_cost);
        int current_gas = 0;
        int start = 0;
        if (total_amount_of_gas < total_cost)
            return -1;
        for (int i = 0; i < gas.size(); ++i) {
            current_gas += (gas[i] - cost[i]);
            if (current_gas < 0) {
                start = i + 1;
                current_gas = 0;
            }
        }
        return start;
    }
};