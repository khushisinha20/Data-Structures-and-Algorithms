//leetcode.com/problems/find-closest-node-to-given-two-nodes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getDistance(vector<int>& edges, int node) {
        vector<int> distance(edges.size(), INT_MAX);
        distance[node] = 0;
        queue<int> nodes;
        nodes.push(node);
        
        while (!nodes.empty()) {
            int currentNode = nodes.front();
            nodes.pop();
            
            int neighbour = edges[currentNode];
            if (neighbour != -1 and distance[currentNode] + 1 < distance[neighbour]) {
                distance[neighbour] = distance[currentNode] + 1;
                nodes.push(neighbour);
            }
        }
        return distance;
    }
    
    int minimizeMaximumDistance(vector<int>& distanceFromNode1, vector<int>& distanceFromNode2) {
        int minMaxDistance = INT_MAX;
        int node = -1;
        
        for (int i = 0; i < distanceFromNode1.size(); ++i) {
            if (max(distanceFromNode1[i], distanceFromNode2[i]) < minMaxDistance) {
                minMaxDistance = max(distanceFromNode1[i], distanceFromNode2[i]);
                node = i;
            }
        }
        
        return node;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> distanceFromNode1 = getDistance(edges, node1);
        vector<int> distanceFromNode2 = getDistance(edges, node2);
        
        return minimizeMaximumDistance(distanceFromNode1, distanceFromNode2);
    }
};