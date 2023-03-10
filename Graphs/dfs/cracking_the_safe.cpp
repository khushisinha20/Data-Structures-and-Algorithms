//leetcode.com/problems/cracking-the-safe/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string result = "";
    unordered_set<string> seen;
     
    bool dfs(string& current, int& n, int& k, int total) {
        if (seen.size() == total) {
            result = current;
            return true;
        }
        
        string lastN = current.substr(current.length() - (n - 1));
        
        for (int neighbour = 0; neighbour < k; ++neighbour) {
            string temporary = lastN + to_string(neighbour);
            current += to_string(neighbour);
            if (seen.find(temporary) == seen.end()) {
                seen.insert(temporary);
                if (dfs(current, n, k, total))
                    return true;
                seen.erase(temporary);
            }
            current.pop_back();
        }
        
        return false;
    }
    
    string crackSafe(int n, int k) {
        string current(n, '0');
        seen.insert(current);
        dfs(current, n, k, pow(k, n));
        return result;
    }
};