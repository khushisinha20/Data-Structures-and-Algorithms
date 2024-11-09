//leetcode.com/problems/closest-room/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });

        int k = queries.size();
        vector<pair<vector<int>, int>> indexedQueries;
        for (int i = 0; i < k; ++i)
            indexedQueries.push_back({queries[i], i});

        sort(indexedQueries.begin(), indexedQueries.end(), [](pair<vector<int>, int>& a, pair<vector<int>, int>& b) {
            return a.first[1] > b.first[1];
        });

        vector<int> result(k, -1);
        set<int> availableRoomIds;
        int roomIndex = 0;

        for (auto& [query, queryIndex]: indexedQueries) {
            int preferred = query[0];
            int minSize = query[1];

            while (roomIndex < rooms.size() and rooms[roomIndex][1] >= minSize) {
                availableRoomIds.insert(rooms[roomIndex][0]);
                ++roomIndex;
            }

            if (availableRoomIds.empty()) {
                result[queryIndex] = -1;
                continue;
            }

            auto lower = availableRoomIds.lower_bound(preferred);

            int closestRoomId = -1;
            if (lower != availableRoomIds.end())
                closestRoomId = *lower;

            if (lower != availableRoomIds.begin()) {
                int smallerId = *prev(lower);
                if (closestRoomId == -1 or abs(smallerId - preferred) < abs(closestRoomId - preferred) or
                   (abs(smallerId - preferred) == abs(closestRoomId - preferred) and smallerId < closestRoomId)) {
                    closestRoomId = smallerId;
                }
            }

            result[queryIndex] = closestRoomId;
        }

        return result;
    }
};
