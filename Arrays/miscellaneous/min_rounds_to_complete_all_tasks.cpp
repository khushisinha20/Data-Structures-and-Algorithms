//leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int min_rounds = 0;
        unordered_map<int, int> task_frequencies;
        for (auto task: tasks)
            ++task_frequencies[task];
        for (auto task_freq: task_frequencies) {
            if (task_freq.second == 1)
                return -1;
            if (task_freq.second == 2 || task_freq.second == 3)
                min_rounds += 1;
            else {
                if ((task_freq.second % 3) % 2 == 0)
                    min_rounds += ((task_freq.second / 3) + ((task_freq.second % 3) / 2));    
                else
                    min_rounds += ((task_freq.second / 3) + (task_freq.second % 3));
            }
        }
        return min_rounds;
    }
};