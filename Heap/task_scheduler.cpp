//leetcode.com/problems/task-scheduler/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> getFrequency(vector<char>& tasks) {
        unordered_map<char, int> frequency;
        for (auto& task: tasks)
            ++frequency[task];
        return frequency;
    }
    
    priority_queue<int> getMaxHeap(unordered_map<char, int>& frequency) {
        priority_queue<int> maxHeap;
        for (auto& entry: frequency)
            maxHeap.push(entry.second);
        return maxHeap;
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        auto frequency = getFrequency(tasks);
        auto maxHeap = getMaxHeap(frequency);
        
        queue<vector<int>> processedTasks;
        int time = 0;
        
        while (!maxHeap.empty() or !processedTasks.empty()) {
            ++time;
            if (!maxHeap.empty()) {
                int maxFrequency = maxHeap.top();
                maxHeap.pop();
                --maxFrequency;
                if (maxFrequency != 0)
                    processedTasks.push({maxFrequency, time + n});
            }
            if (!processedTasks.empty() and processedTasks.front()[1] == time) {
                maxHeap.push(processedTasks.front()[0]);
                processedTasks.pop();
            }            
        }
        
        return time;
    }
};