//leetcode.com/problems/two-city-scheduling/submissions/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool comparator(vector<int>& a, vector<int>& b) {
    return (a[0] - a[1]) < (b[0] - b[1]);
}
    
class Solution {
public:
    int twoCitySchedCost(vector<vector<int> >& costs) {
        sort(costs.begin(), costs.end(), comparator);
        int min_cost = 0;
        for (int i = 0; i < costs.size() / 2; ++i) 
            min_cost += costs[i][0];
        for (int i = costs.size() / 2; i < costs.size(); ++i) 
            min_cost += costs[i][1];
        return min_cost;
    }
};