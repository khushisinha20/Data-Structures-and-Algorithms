//leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0 || s.empty()) 
                s.push(asteroids[i]);
            else {
                while (!s.empty() && s.top() < abs(asteroids[i]) && s.top() > 0) 
                    s.pop();
                if (!s.empty() && s.top() == abs(asteroids[i])) 
                    s.pop();
                else {
                    if (s.empty() || s.top() < 0)
                        s.push(asteroids[i]);
                }
            }
        }
        vector<int> res(s.size());
        for (int i = res.size() - 1; i >= 0; --i) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};