//practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void findIndegrees(vector<vector<int>>& adjacencyList, vector<int>& indegrees) {
        for (int vertex = 0; vertex < indegrees.size(); ++vertex) {
            for (auto adjacentVertex: adjacencyList[vertex]) {
                ++indegrees[adjacentVertex];
            }
        }
    }
    
    void storeZeroIndegreeNodes(vector<int>& indegrees, queue<int>& zeroIndegreeNodes) {
        for (int vertex = 0; vertex < indegrees.size(); ++vertex)
            if (indegrees[vertex] == 0)
                zeroIndegreeNodes.push(vertex);
    }
    
    void createGraph(string dict[], int N, int K, vector<vector<int>>& adjacencyList) {
        for (int i = 0; i < N - 1; ++i) {
            string firstWord = dict[i];
            string secondWord = dict[i + 1];
            for (int j = 0; j < min(firstWord.length(), secondWord.length()); ++j) {
                if (firstWord[j] != secondWord[j]) {
                    adjacencyList[firstWord[j] - 'a'].push_back(secondWord[j] - 'a');
                    break;
                }
            }
        }
    }
    
    void bfs(vector<int>& indegrees, queue<int>& zeroIndegreeNodes, vector<vector<int>>& adjacencyList, string& topologicalSort) {
        while (!zeroIndegreeNodes.empty()) {
            int currentNode = zeroIndegreeNodes.front();
            zeroIndegreeNodes.pop();
            
            topologicalSort += char(currentNode + 'a');
            for (auto adjacentNode: adjacencyList[currentNode]) {
                --indegrees[adjacentNode];
                if (indegrees[adjacentNode] == 0)
                    zeroIndegreeNodes.push(adjacentNode);
            }
        }
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adjacencyList(K);
        createGraph(dict, N, K, adjacencyList);
        vector<int> indegrees(K, 0);
        findIndegrees(adjacencyList, indegrees);
        queue<int> zeroIndegreeNodes;
        storeZeroIndegreeNodes(indegrees, zeroIndegreeNodes);
        string topologicalSort;
        bfs(indegrees, zeroIndegreeNodes, adjacencyList, topologicalSort);
        return topologicalSort;
    }
};