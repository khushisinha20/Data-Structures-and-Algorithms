//leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(int n) {
        if (n == 0 or n == 1)
            return n;

        queue<int> orangeQueue;
        orangeQueue.push(n);
        unordered_map<int, int> distance;
        distance[n] = 0;

        while (!orangeQueue.empty()) {
            int current = orangeQueue.front();
            orangeQueue.pop();

            if (current == 0)
                return distance[current];

            if (distance.find(current - 1) == distance.end()) {
                distance[current - 1] = distance[current] + 1;
                orangeQueue.push(current - 1);
            }

            if (current % 2 == 0 and distance.find(current / 2) == distance.end()) {
                distance[current / 2] = distance[current] + 1;
                orangeQueue.push(current / 2);
            }

            if (current % 3 == 0 and distance.find(current / 3) == distance.end()) {
                distance[current / 3] = distance[current] + 1;
                orangeQueue.push(current / 3);
            }
        }

        return -1;
    }
};
