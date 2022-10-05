//leetcode.com/problems/task-scheduler/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void storeFrequencies(vector<char>& tasks, unordered_map<char, int>& frequency) {
        for (auto task: tasks)
            ++frequency[task];
    }
    
    void storeInHeap(unordered_map<char, int>& frequency, priority_queue<pair<int, char>>& maxFrequencyHeap) {
        for (auto freq: frequency) {
            maxFrequencyHeap.push({freq.second, freq.first});
        }
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequency;
        storeFrequencies(tasks, frequency);
        priority_queue<pair<int, char>> maxFrequencyHeap;
        storeInHeap(frequency, maxFrequencyHeap);
        queue<pair<int, char>> completedTasks;
        int completionTime = 0;
        int tasksProcessed = 0;
        
        while (!maxFrequencyHeap.empty()) {
            char currentTask = maxFrequencyHeap.top().second;
            int currentTaskCount = maxFrequencyHeap.top().first;
            maxFrequencyHeap.pop();
            ++completionTime;
            ++tasksProcessed;
            completedTasks.push({currentTaskCount - 1, currentTask});
            for (int i = 0; i < n; ++i) {
                if (maxFrequencyHeap.empty()) {
                    if (tasksProcessed == tasks.size())
                        break;
                    ++completionTime;
                } else {
                    currentTask = maxFrequencyHeap.top().second;
                    currentTaskCount = maxFrequencyHeap.top().first;
                    maxFrequencyHeap.pop();
                    ++tasksProcessed;
                    ++completionTime;
                    completedTasks.push({currentTaskCount - 1, currentTask});
                }
            }
            while (!completedTasks.empty()) {
                auto task = completedTasks.front();
                completedTasks.pop();
                if (task.first) 
                    maxFrequencyHeap.push(task);   
            }
        }
        return completionTime;
    }
};