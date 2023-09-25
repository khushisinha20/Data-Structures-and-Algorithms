//leetcode.com/problems/shopping-offers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> memo;
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string needsStr = "";
        
        int n = needs.size();
        for (int i = 0; i < n; ++i)
            needsStr += to_string(needs[i]) + "-";
        
        if (memo.find(needsStr) != memo.end())
            return memo[needsStr];
        
        int result = 0;
        
        for (int i = 0; i < n; ++i)
            result += needs[i] * price[i];
        
        for (auto& offer: special) {
            bool validOffer = true;
            for (int i = 0; i < n; i++) {
                if (offer[i] > needs[i]) {
                    validOffer = false;
                    break;
                }
            }
            
            if (validOffer) {
                for (int i = 0; i < n; i++) 
                    needs[i] -= offer[i];
                result = min(result, offer[n] + shoppingOffers(price, special, needs));
                for (int i = 0; i < n; i++) 
                    needs[i] += offer[i];
            }
        }
        
        return memo[needsStr] = result;
    }
};