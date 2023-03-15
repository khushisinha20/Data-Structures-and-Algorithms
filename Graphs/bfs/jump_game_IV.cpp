//leetcode.com/problems/jump-game-iv/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillOccurences(unordered_map<int, vector<int>>& occurences, vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
            occurences[arr[i]].push_back(i);
    }
    
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> occurences;
        fillOccurences(occurences, arr);
        queue<int> indices;
        indices.push(0);
        vector<bool> visited(arr.size(), false);
        int jumps = 0;
        visited[0] = true;
        while (!indices.empty()) {
            int size = indices.size();
            while (size--) {
                int currentIndex = indices.front();
                indices.pop();

                if (currentIndex == arr.size() - 1)
                    return jumps;

                vector<int>& next = occurences[arr[currentIndex]];
                next.push_back(currentIndex + 1);
                next.push_back(currentIndex - 1);

                for (auto neighborNode: next) {
                    if (!(neighborNode < 0 or neighborNode >= arr.size() or visited[neighborNode])) {
                        visited[neighborNode] = true;
                        indices.push(neighborNode);
                    }
                }

                occurences[arr[currentIndex]].clear();
            }
            ++jumps;
        }
        return jumps;
    }
};