//leetcode.com/problems/super-washing-machines/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int totalCloths = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (totalCloths % n != 0)
            return -1;
        
        int clothsInEachMachine = totalCloths / n;
        int maxCloths = *max_element(machines.begin(), machines.end());
        int cumulativeDifference = 0;
        int ans = 0;
        
        for (int machine: machines) {
            cumulativeDifference += machine - clothsInEachMachine;
            ans = max(ans, abs(cumulativeDifference));
        }
        
        ans = max(ans, maxCloths - clothsInEachMachine);
        return ans;
    }
};