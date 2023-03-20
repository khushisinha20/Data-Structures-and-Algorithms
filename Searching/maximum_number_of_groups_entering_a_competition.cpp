//leetcode.com/problems/maximum-number-of-groups-entering-a-competition/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        long long low = 0;
        long long high = grades.size();
        long long answer = 1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if ((mid * (mid + 1)) / 2 <= grades.size()) {
                answer = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        
        return answer;
    }
};