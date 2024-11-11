//leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;
        set<int> availableServers;
        for (int i = 0; i < k; ++i) {
            availableServers.insert(i);
        }

        vector<int> requestCount(k, 0);
        for (int i = 0; i < arrival.size(); ++i) {
            int currentTime = arrival[i];
            int duration = load[i];

            while (!busyServers.empty() && busyServers.top().first <= currentTime) {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }

            int serverIndex = i % k;
            auto it = availableServers.lower_bound(serverIndex);
            if (it == availableServers.end()) {
                it = availableServers.begin();
            }

            if (it != availableServers.end()) {
                int assignedServer = *it;
                availableServers.erase(it);
                busyServers.push({currentTime + duration, assignedServer});
                ++requestCount[assignedServer];
            }
        }

        int maxRequests = *max_element(requestCount.begin(), requestCount.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};
