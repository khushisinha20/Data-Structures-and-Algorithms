//leetcode.com/problems/find-minimum-time-to-finish-all-jobs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<long long, long long> memo;
    int result = INT_MAX;

    unsigned long long getHashCode(vector<int>& workers) {
        unsigned long long state = 0;
        for (auto worker: workers)
            state = (state << 5) | worker;
        return state;
    }

    void helper(vector<int>& jobs, int& k, int index, vector<int>& workers, int maxWorkTime) {
        if (maxWorkTime >= result)
            return;

        if (index >= jobs.size()) {
            result = maxWorkTime;
            return;
        }

        int workTime = jobs[index];

        for (int i = 0; i < k; ++i) {
            if (workers[i] + workTime < result) {
                workers[i] += workTime;

                unsigned long long currentState = getHashCode(workers);

                if (!memo.count(currentState) or maxWorkTime + workTime < memo[currentState]) {
                    memo[currentState] = maxWorkTime + workTime;
                    helper(jobs, k, index + 1, workers, max(maxWorkTime, workers[i]));
                }

                workers[i] -= workTime;
            }
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int& k) {
        sort(jobs.rbegin(), jobs.rend());
        vector<int> workers(k, 0);
        helper(jobs, k, 0, workers, 0);
        return result;
    }
};
