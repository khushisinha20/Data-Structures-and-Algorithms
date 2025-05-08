//leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = INT_MAX;

    void backtrack(vector<int>& tasks, vector<int>& sessions, int sessionTime, int index) {
        if (index == tasks.size()) {
            result = min(result, (int)sessions.size());
            return;
        }

        if (sessions.size() >= result)
            return;

        for (int i = 0; i < sessions.size(); ++i) {
            if (sessions[i] + tasks[index] <= sessionTime) {
                sessions[i] += tasks[index];
                backtrack(tasks, sessions, sessionTime, index + 1);
                sessions[i] -= tasks[index];
            }
        }

        sessions.push_back(tasks[index]);
        backtrack(tasks, sessions, sessionTime, index + 1);
        sessions.pop_back();
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.rbegin(), tasks.rend());
        vector<int> sessions;
        backtrack(tasks, sessions, sessionTime, 0);
        return result;
    }
};
