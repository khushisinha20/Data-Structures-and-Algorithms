//leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    bool detectCycle(vector<vector<int>>& graph, vector<bool>& visitedNode, vector<bool>& visitedPath, vector<bool>& isPartOfCycle, int node) {
        
        visitedNode[node] = true;
        visitedPath[node] = true;
        isPartOfCycle[node] = true;
        
        for (auto adjacentNode: graph[node]) {
            if (!visitedNode[adjacentNode]) {
                if (detectCycle(graph, visitedNode, visitedPath, isPartOfCycle, adjacentNode)) 
                    return true;
            } else {
                if (visitedPath[adjacentNode])
                    return true;
            }
        }
        
        visitedPath[node] = false;
        isPartOfCycle[node] = false;
        return false;
    }
    
    void findSafeNodes(vector<bool>& isPartOfCycle, vector<int>& safeNodes) {
        for (int node = 0; node < isPartOfCycle.size(); ++node)
            if (!isPartOfCycle[node])
                safeNodes.push_back(node);
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visitedPath(graph.size(), false);
        vector<bool> visitedNode(graph.size(), false);
        vector<bool> isPartOfCycle(graph.size(), false);
        vector<int> safeNodes;
        
        for (int node = 0; node < graph.size(); ++node)
            if (!visitedNode[node])
                detectCycle(graph, visitedNode, visitedPath, isPartOfCycle, node);
        
        findSafeNodes(isPartOfCycle, safeNodes);
        return safeNodes;
    }
};