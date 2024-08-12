//leetcode.com/problems/race-car/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stateRepresentation(int position, int speed) {
        char DELIMETER = '-';
        return to_string(position) + DELIMETER + to_string(speed);
    }

    int racecar(int target) {
        queue<tuple<int, int, int>> states;
        states.push({0, 1, 0});
        unordered_set<string> visited;
        visited.insert(stateRepresentation(0, 1));

        while (!states.empty()) {
            auto [position, speed, steps] = states.front();
            states.pop();

            if (position == target)
                return steps;

            int newPosition = position + speed;
            int newSpeed = speed * 2;
            string stateA = stateRepresentation(newPosition, newSpeed);
            if (newPosition >= 0 and newPosition < 2 * target and visited.find(stateA) == visited.end()) {
                states.push({newPosition, newSpeed, steps + 1});
                visited.insert(stateA);
            }

            newSpeed = speed > 0 ? -1 : 1;
            string stateR = stateRepresentation(position, newSpeed);
            if (visited.find(stateR) == visited.end()) {
                states.push({position, newSpeed, steps + 1});
                visited.insert(stateR);
            }
        }

        return -1;
    }
};
