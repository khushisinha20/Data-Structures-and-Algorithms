//leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<vector<int>>& adjacencyList, vector<vector<int>>& prerequisites) {
        for (auto prerequisite: prerequisites)
            adjacencyList[prerequisite[1]].push_back(prerequisite[0]);
    }
    
    void fillIndegrees(vector<int>& indegree, vector<vector<int>>& adjacencyList) {
        for (int vertex = 0; vertex < indegree.size(); ++vertex) {
            for (auto adjacentVertex: adjacencyList[vertex]) {
                ++indegree[adjacentVertex];
            }
        }
    }
        
    void storeZeroIndegreeNodes(vector<int>& indegree, queue<int>& zeroIndegreeNodes) {
        for (int vertex = 0; vertex < indegree.size(); ++vertex)
            if (indegree[vertex] == 0)
                zeroIndegreeNodes.push(vertex);
    }
    
    void bfs(vector<vector<int>>& adjacencyList, queue<int>& zeroIndegreeNodes, vector<int>& indegree, int& countOfNodes) {
        while (!zeroIndegreeNodes.empty()) {
            int currentNode = zeroIndegreeNodes.front();
            zeroIndegreeNodes.pop();
            ++countOfNodes;
            
            for (auto adjacentNode: adjacencyList[currentNode]) {
                --indegree[adjacentNode];
                if (indegree[adjacentNode] == 0)
                    zeroIndegreeNodes.push(adjacentNode);
            }
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        createAdjacencyList(adjacencyList, prerequisites);
        vector<int> indegree(numCourses, 0);
        fillIndegrees(indegree, adjacencyList);
        queue<int> zeroIndegreeNodes;
        storeZeroIndegreeNodes(indegree, zeroIndegreeNodes);
        int countOfDoableCourses = 0;
        bfs(adjacencyList, zeroIndegreeNodes, indegree, countOfDoableCourses);
        return countOfDoableCourses == numCourses;
    }
};