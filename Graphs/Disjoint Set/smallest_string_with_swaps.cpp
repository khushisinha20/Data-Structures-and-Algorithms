#include <bits/stdc++.h>
using namespace std;

class disjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    disjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionOfNodes(int u, int v) {
        int parentOfU = find(u);
        int parentOfV = find(v);

        if (parentOfU == parentOfV)
            return;

        if (rank[parentOfU] < rank[parentOfV])
            parent[parentOfU] = parentOfV;
        else if (rank[parentOfV] < rank[parentOfU])
            parent[parentOfV] = parentOfU;
        else {
            parent[parentOfV] = parentOfU;
            ++rank[parentOfU];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        disjointSet dsu(n);

        for (auto& pair: pairs)
            dsu.unionOfNodes(pair[0], pair[1]);

        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            components[root].push_back(i);
        }

        for (auto& component: components) {
            string temp;
            for (int index: component.second)
                temp.push_back(s[index]);
            sort(temp.begin(), temp.end());
            sort(component.second.begin(), component.second.end());
            for (int i = 0; i < component.second.size(); ++i)
                s[component.second[i]] = temp[i];
        }

        return s;
    }
};
