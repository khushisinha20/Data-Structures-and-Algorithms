//leetcode.com/problems/open-the-lock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> codes;

        if (dead.find("0000") == dead.end()) {
            codes.push({"0000", 0});
            visited.insert("0000");
        }

        while (!codes.empty()) {
            string currentCode = codes.front().first;
            int turns = codes.front().second;
            codes.pop();

            if (currentCode == target)
                return turns;

            for (int i = 0; i < 4; ++i) {
                string nextAfterIncrementing = currentCode.substr(0, i) + to_string((currentCode[i] - '0' + 1) % 10) + currentCode.substr(i + 1);
                string nextAfterDecrementing = currentCode.substr(0, i) + to_string((currentCode[i] - '0' - 1 + 10) % 10) + currentCode.substr(i + 1);

                if (dead.find(nextAfterIncrementing) == dead.end() and visited.find(nextAfterIncrementing) == visited.end()) {
                    visited.insert(nextAfterIncrementing);
                    codes.push({nextAfterIncrementing, turns + 1});
                }

                if (dead.find(nextAfterDecrementing) == dead.end() and visited.find(nextAfterDecrementing) == visited.end()) {
                    visited.insert(nextAfterDecrementing);
                    codes.push({nextAfterDecrementing, turns + 1});
                }
            }
        }

        return -1;
    }
};
