#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/set-intersection-size-at-least-two/

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int minSize = 0;
        int last = -1;
        int secondLast = -1;
        
        for (auto& interval: intervals) {
            int start = interval[0];
            int end = interval[1];
            
            if (start > last) {
                minSize += 2;
                secondLast = end - 1;
                last = end;
            } else if (start == last or start > secondLast) {
                minSize += 1;
                secondLast = last;
                last = end;
            }
        }
        
        return minSize;
    }
};