//leetcode.com/problems/escape-a-large-maze/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesWithinBounds(int x, int y) {
        return x >= 0 and x < 1000000 and y >= 0 and y < 1000000;
    }

    long long toKey(long long x, long long y) {
        long long offset = 1000000;
        return x * offset + y;
    }

    bool bfs(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blockedSet;
        for (auto& block: blocked)
            blockedSet.insert(toKey(block[0], block[1]));

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        unordered_set<long long> visited;
        queue<pair<int, int>> coordinates;
        coordinates.push({source[0], source[1]});
        visited.insert(toKey(source[0], source[1]));

        int limit = 100000;

        while (!coordinates.empty()) {
            auto [x, y] = coordinates.front();
            coordinates.pop();

            if (x == target[0] and y == target[1])
                return true;

            for (auto& direction: directions) {
                int newX = x + direction[0];
                int newY = y + direction[1];

                if (liesWithinBounds(newX, newY)) {
                    long long position = toKey(newX, newY);
                    if (!visited.count(position) and !blockedSet.count(position)) {
                        coordinates.push({newX, newY});
                        visited.insert(position);

                        if (visited.size() > limit)
                            return true;
                    }
                }
            }
        }

        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return bfs(blocked, source, target) and bfs(blocked, target, source);
    }
};
