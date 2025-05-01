//leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - k, workers.end());

        int usedPills = 0;
        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];
            auto it = availableWorkers.end();
            --it;
            if (*it >= task)
                availableWorkers.erase(it);
            else {
                if (usedPills == pills)
                    return false;
                auto canBoost = availableWorkers.lower_bound(task - strength);
                if (canBoost == availableWorkers.end())
                    return false;
                availableWorkers.erase(canBoost);
                ++usedPills;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0;
        int high = min(tasks.size(), workers.size());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
