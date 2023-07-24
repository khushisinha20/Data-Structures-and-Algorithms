//leetcode.com/problems/knight-dialer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int knightDialer(int n) {
        unordered_map<int, vector<int>> movement;
        movement[0] = {4, 6};
        movement[1] = {6, 8};
        movement[2] = {7, 9};
        movement[3] = {4, 8};
        movement[4] = {0, 3, 9};
        movement[6] = {0, 1, 7};
        movement[7] = {2, 6};
        movement[8] = {1, 3};
        movement[9] = {2, 4};
        
        vector<int> previousNumberLengths(10, 1);
        
        for (int i = 2; i <= n; ++i) {
            vector<int> currentNumberLengths(10);
            for (auto [key, value]: movement) {
                for (auto _: value) {
                    currentNumberLengths[key] = (currentNumberLengths[key] + previousNumberLengths[_]) % MOD;
                }
            }
            previousNumberLengths = currentNumberLengths;
        }
        
        int ans = 0;
        for (auto& _: previousNumberLengths)
            ans = (ans + _) % MOD;
        
        return ans;
    } 
};