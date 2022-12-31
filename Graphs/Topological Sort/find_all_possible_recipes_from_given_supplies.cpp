//leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<string>& recipes, vector<vector<string>>& ingredients, unordered_map<string, vector<string>>& adjacencyList) {
        for (int i = 0; i < recipes.size(); ++i) {
            for (int j = 0; j < ingredients[i].size(); ++j) {
                adjacencyList[ingredients[i][j]].push_back(recipes[i]);
            }
        }
    }
    
    void fillIndegrees(unordered_map<string, vector<string>>& adjacencyList, unordered_map<string, int>& indegree) {
        for (auto item = adjacencyList.begin(); item != adjacencyList.end(); ++item) {
            for (auto ingredient: adjacencyList[item -> first]) {
                ++indegree[ingredient];
            }
        }
    }
    
    void storeSupplies(vector<string>& supplies, queue<string>& zeroIndegreeNodes) {
        for (auto supply: supplies)
            zeroIndegreeNodes.push(supply);
    }
    
    void bfs(unordered_set<string>& possibleRecipes, unordered_map<string, vector<string>>& adjacencyList, queue<string>& zeroIndegreeNodes, unordered_map<string, int>& indegree, vector<string>& recipesCreated) {
        while (!zeroIndegreeNodes.empty()) {
            string currentItem = zeroIndegreeNodes.front();
            zeroIndegreeNodes.pop();
            
            if (possibleRecipes.find(currentItem) != possibleRecipes.end())
                recipesCreated.push_back(currentItem);
            
            for (auto item: adjacencyList[currentItem]) {
                --indegree[item];
                if (!indegree[item])
                    zeroIndegreeNodes.push(item);
            }
        }
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adjacencyList;
        createAdjacencyList(recipes, ingredients, adjacencyList);
        unordered_map<string, int> indegree;
        fillIndegrees(adjacencyList, indegree);
        queue<string> zeroIndegreeNodes;
        storeSupplies(supplies, zeroIndegreeNodes);
        unordered_set<string> possibleRecipes(recipes.begin(), recipes.end());
        vector<string> recipesCreated;
        bfs(possibleRecipes, adjacencyList, zeroIndegreeNodes, indegree, recipesCreated);
        return recipesCreated;
    }
};