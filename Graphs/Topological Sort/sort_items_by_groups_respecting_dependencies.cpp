//leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    queue<int> getZeroIndegreeNodes(vector<int>& indegree) {
        queue<int> zeroIndegreeNodes;
        for (int i = 0; i < indegree.size(); ++i)
            if (indegree[i] == 0)
                zeroIndegreeNodes.push(i);
        return zeroIndegreeNodes;
    }
    
    vector<int> topologicalSort(unordered_map<int, vector<int>>& graph, vector<int>& indegree) {
        queue<int> zeroIndegreeNodes = getZeroIndegreeNodes(indegree);
        vector<int> result;
        
        while (!zeroIndegreeNodes.empty()) {
            int currentNode = zeroIndegreeNodes.front();
            zeroIndegreeNodes.pop();
            
            result.push_back(currentNode);
            
            for (auto& neighbour: graph[currentNode]) {
                --indegree[neighbour];
                if (indegree[neighbour] == 0)
                    zeroIndegreeNodes.push(neighbour);
            }
        }
        
        return result.size() == graph.size() ? result : vector<int> ();
    }
    
    void assignGroupsToLoners(vector<int>& group, int& m) {
        for (int i = 0; i < group.size(); ++i)
            if (group[i] == -1)
                group[i] = m++;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        assignGroupsToLoners(group, m);
        
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i)
            itemGraph[i] = vector<int> ();
        
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(m, 0);
        for (int i = 0; i < m; ++i)
            groupGraph[i] = vector<int> ();
        
        for (int item = 0; item < n; ++item) {
            for (auto& beforeItem: beforeItems[item]) {
                itemGraph[beforeItem].push_back(item);
                ++itemIndegree[item];
                
                if (group[item] != group[beforeItem]) {
                    int currentItemGroup = group[item];
                    int previousItemGroup = group[beforeItem];
                    
                    groupGraph[previousItemGroup].push_back(currentItemGroup);
                    ++groupIndegree[currentItemGroup];
                }
            }
        }
        
        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);
        
        if (itemOrder.empty() or groupOrder.empty())
            return {};
        
        unordered_map<int, vector<int>> groupToItemsMap;
        for (auto item: itemOrder) {
            int itemGroup = group[item];
            groupToItemsMap[itemGroup].push_back(item);
        }
        
        vector<int> result;
        for (int group: groupOrder) {
            for (int i = 0; i < groupToItemsMap[group].size(); ++i) {
                result.push_back(groupToItemsMap[group][i]);
            }
        }
        
        return result;
    }
};