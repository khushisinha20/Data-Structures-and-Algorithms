//leetcode.com/problems/minimum-speed-to-arrive-on-time/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& dist, double& hour, double speed) {
        double time = 0;
        
        for (int i = 0; i < dist.size() - 1; ++i)
            time += ceil(dist[i] / speed); // Use ceil instead of (dist[i] + speed - 1) / speed
        
        time += dist.back() / speed;
        return time <= hour; // Use hour instead of speed here
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int minSpeed = -1; // Initialize to -1, as specified in the problem.
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Correct the variable name "mid" here
            if (isValid(dist, hour, mid)) {
                minSpeed = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        
        return minSpeed;
    }
};
