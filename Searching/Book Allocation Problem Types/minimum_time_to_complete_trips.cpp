//leetcode.com/problems/minimum-time-to-complete-trips/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long tripsForGivenTime(vector<int>& times, long long& mid) {
        long long trips = 0;
        for (auto time: times) 
            trips += (mid / ((long long)time));
        return trips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lowestTime = 1;
        long long highestTime = 1e14;
        
        while (lowestTime < highestTime) {
            long long mid = lowestTime + (highestTime - lowestTime) / 2;
            if (tripsForGivenTime(time, mid) >= totalTrips)
                highestTime = mid;
            else
                lowestTime = mid + 1;
        }
        
        return lowestTime;
    }
};