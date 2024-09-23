//leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int totalEnergy = 0;
        for (auto& task: tasks)
            totalEnergy += task[0];

        sort(tasks.begin(), tasks.end(), comparator);
        int currentEnergy = totalEnergy;
        int additionalEnergy = 0;

        for (auto& task: tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (currentEnergy < minimum) {
                additionalEnergy += (minimum - currentEnergy);
                currentEnergy = minimum;
            }

            currentEnergy -= actual;
        }

        return totalEnergy + additionalEnergy;
    }
};
