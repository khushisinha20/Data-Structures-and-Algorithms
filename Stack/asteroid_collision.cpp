//leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;
        
        for (auto& asteroid: asteroids) {
            bool exploded = false;
            
            while (!asteroidStack.empty() and asteroid < 0 and asteroidStack.top() > 0) {
                if (abs(asteroid) > asteroidStack.top())
                    asteroidStack.pop();
                else if (asteroidStack.top() == abs(asteroid)) {
                    exploded = true;
                    asteroidStack.pop();
                    break;
                } else {
                    exploded = true;
                    break;
                }
            }
            
            if (!exploded)
                asteroidStack.push(asteroid);
        }
        
        vector<int> result(asteroidStack.size());
        
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] = asteroidStack.top();
            asteroidStack.pop();
        }
        
        return result;
    }
};