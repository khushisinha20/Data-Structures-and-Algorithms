//leetcode.com/problems/maximum-candies-you-can-get-from-boxes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> toProcess;
        unordered_set<int> availableBoxes;

        for (int box: initialBoxes)
            toProcess.push(box);

        int totalCandies = 0;

        while (!toProcess.empty()) {
            int currentBox = toProcess.front();
            toProcess.pop();

            if (status[currentBox] == 1) {
                totalCandies += candies[currentBox];

                for (int key: keys[currentBox]) {
                    status[key] = 1;
                    if (availableBoxes.find(key) != availableBoxes.end()) {
                        toProcess.push(key);
                        availableBoxes.erase(key);
                    }
                }

                for (int newBox: containedBoxes[currentBox]) {
                    if (status[newBox] == 1)
                        toProcess.push(newBox);
                    else
                        availableBoxes.insert(newBox);
                }
            } else {
                availableBoxes.insert(currentBox);
            }
        }

        return totalCandies;
    }
};
