//leetcode.com/problems/self-crossing/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        for (int i = 3; i < distance.size(); ++i) {
            if (distance[i - 3] >= distance[i - 1] and distance[i] >= distance[i - 2])
                return true;
            else if (i >= 4 and distance[i - 3] == distance[i - 1] and (distance[i - 4] + distance[i]) >= distance[i - 2])
                return true;
            else if (i >= 5 and distance[i - 2] >= distance[i - 4] and distance[i - 3] >= distance[i - 1] and (distance[i - 1] + distance[i - 5]) >= distance[i - 3] and (distance[i] + distance[i - 4]) >= distance[i - 2])
                return true;
        }
        return false;
    }
};