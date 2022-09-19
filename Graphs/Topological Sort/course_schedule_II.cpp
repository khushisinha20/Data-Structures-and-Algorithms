//leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<vector<int>>& prerequisites, vector<vector<int>>& adjacencyList) {
        for (auto prerequisite: prerequisites) 
            adjacencyList[prerequisite[1]].push_back(prerequisite[0]);
    }
    
    void findIndegrees(vector<int>& indegrees, vector<vector<int>>& adjacencyList, int& numCourses) {
        for (int edge = 0; edge < numCourses; ++edge) {
            for (auto vertex: adjacencyList[edge]) {
                ++indegrees[vertex];
            }
        }
    }
    
    void storeVerticesWithZeroIndegree(vector<int>& indegrees, queue<int>& zeroIndegreeVertices) {
        for (int vertex = 0; vertex < indegrees.size(); ++vertex)
            if (indegrees[vertex] == 0)
                zeroIndegreeVertices.push(vertex);
    }
    
    void bfs(vector<vector<int>>& adjacencyList, vector<int>& indegrees, vector<int>& topologicalSortedVertices, queue<int>& zeroIndegreeVertices) {
        while (!zeroIndegreeVertices.empty()) {
            int currentVertex = zeroIndegreeVertices.front();
            zeroIndegreeVertices.pop();
            topologicalSortedVertices.push_back(currentVertex);
            
            for (auto adjacentVertex: adjacencyList[currentVertex]) {
                --indegrees[adjacentVertex];
                if (indegrees[adjacentVertex] == 0)
                    zeroIndegreeVertices.push(adjacentVertex);
            }
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        createAdjacencyList(prerequisites, adjacencyList);
        vector<int> indegrees(numCourses, 0);
        findIndegrees(indegrees, adjacencyList, numCourses);
        queue<int> zeroIndegreeVertices;
        storeVerticesWithZeroIndegree(indegrees, zeroIndegreeVertices);
        vector<int> topologicalSortedVertices;
        bfs(adjacencyList, indegrees, topologicalSortedVertices, zeroIndegreeVertices);
        if (topologicalSortedVertices.size() == numCourses)
            return topologicalSortedVertices;
        return {};
    }
};