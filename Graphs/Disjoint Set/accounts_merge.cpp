//leetcode.com/problems/accounts-merge/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class disjointSet {
        public:
        vector<int> parent;
        vector<int> rank;
        disjointSet(int n) {
            parent.resize(n + 1);
            for (int i = 0; i <= n; ++i)
                parent[i] = i;
            rank.resize(n + 1, 0);
        }
        
        int find(int node) {
            if (parent[node] == node)
                return node;
            parent[node] = find(parent[node]);
            return parent[node];
        }
        
        void unionByRank(int u, int v) {
            int parentOfU = find(u);
            int parentOfV = find(v);
            if (parentOfU == parentOfV)
                return;
            if (parentOfU < parentOfV)
                parent[parentOfU] = parentOfV;
            else if (parentOfV < parentOfU)
                parent[parentOfV] = parentOfU;
            else {
                parent[parentOfV] = parentOfU;
                ++rank[parentOfU];
            }
        }
    };
    
    void createMappings(vector<vector<string>>& accounts, unordered_map<string, int>& mappings, disjointSet& ds) {
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (mappings.find(accounts[i][j]) == mappings.end()) 
                    mappings[accounts[i][j]] = i;
                else 
                    ds.unionByRank(i, mappings[accounts[i][j]]);
            }
        }
    }
    
    void mergeAccounts(vector<vector<string>>& accounts, unordered_map<string, int>& mappings, vector<vector<string>>& mergedAccounts, disjointSet& ds) {
        for (auto mapping: mappings) {
            string mail = mapping.first;
            int parent = ds.find(mapping.second);
            mergedAccounts[parent].push_back(mail);
        }
    }
    
    void formatResult(vector<vector<string>>& mergedAccounts, vector<vector<string>>& result, vector<vector<string>>& accounts) {
        for (int i = 0; i < accounts.size(); ++i) {
            if (mergedAccounts[i].empty())
                continue;
            sort(mergedAccounts[i].begin(), mergedAccounts[i].end());
            vector<string> currentAccount;
            currentAccount.push_back(accounts[i][0]);
            for (auto mergedAccount: mergedAccounts[i])
                currentAccount.push_back(mergedAccount);
            result.push_back(currentAccount);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        disjointSet ds(accounts.size());
        unordered_map<string, int> mappings;
        createMappings(accounts, mappings, ds);
        vector<vector<string>> mergedAccounts(accounts.size());
        mergeAccounts(accounts, mappings, mergedAccounts, ds);
        vector<vector<string>> result;
        formatResult(mergedAccounts, result, accounts);
        return result;
    }
};