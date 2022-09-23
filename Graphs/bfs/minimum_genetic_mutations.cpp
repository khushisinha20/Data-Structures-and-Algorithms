#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> mutations;
        mutations.push({start, 0});
        unordered_set<string> unprocessedMutations(bank.begin(), bank.end());
        unprocessedMutations.erase(start);
        vector<char> genes = {'A', 'C', 'G', 'T'};
        
        while (!mutations.empty()) {
            int size = mutations.size();
            string currentMutation = mutations.front().first;
            int steps = mutations.front().second;
            mutations.pop();
            
            if (currentMutation == end)
                return steps;
            
            for (int i = 0; i < currentMutation.length(); ++i) {
                char originalMutation = currentMutation[i];
                for (auto& gene: genes) {
                    currentMutation[i] = gene;
                    if (unprocessedMutations.find(currentMutation) != unprocessedMutations.end()) {
                        unprocessedMutations.erase(currentMutation);
                        mutations.push({currentMutation, steps + 1});
                    }
                }
                currentMutation[i] = originalMutation;
            }
        }
        return -1;
    }
};