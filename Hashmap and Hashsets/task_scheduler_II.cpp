//leetcode.com/problems/task-scheduler-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long> nextTime;
        long long currentTime = 1;
        
        for (auto& task: tasks) {
            if (nextTime.find(task) != nextTime.end())
                currentTime = max(currentTime, nextTime[task]);
            nextTime[task] = currentTime + space + 1;
            ++currentTime;
        }
        
        return currentTime - 1;
    }
};