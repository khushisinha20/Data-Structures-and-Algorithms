//leetcode.com/problems/keys-and-rooms/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int room, vector<bool>& visited, vector<vector<int>>& rooms) {
        visited[room] = true;
        for (auto key: rooms[room]) {
            if (!visited[key]) {
                visited[key] = true;
                dfs(key, visited, rooms);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int totalRooms = rooms.size();
        vector<bool> visited(totalRooms, false);
        dfs(0, visited, rooms);
        for (auto isVisited: visited)
            if (!isVisited)
                return false;
        return true;
    }
};