//leetcode.com/problems/divisor-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> memo;
    
    bool canWin(int n) {
        if (n == 1)
            return false;
        
        if (memo.find(n) != memo.end())
            return memo[n];
        
        bool aliceWins = false;
        
        for (int x = 1; x < n; ++x) {
            if (n % x == 0) {
                if (!canWin(n - x)) {
                    aliceWins = true;
                    break;
                }
            }
        }
        
        return memo[n] = aliceWins;
    }
    
    bool divisorGame(int n) {
        return canWin(n);
    }
};