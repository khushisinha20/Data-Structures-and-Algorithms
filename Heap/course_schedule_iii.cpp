//leetcode.com/problems/course-schedule-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comparator);
        priority_queue<int> maxHeap;
        int totalDuration = 0;
        
        for (auto& course: courses) {
            totalDuration += course[0];
            maxHeap.push(course[0]);
            if (totalDuration > course[1]) {
                totalDuration -= maxHeap.top();
                maxHeap.pop();
            }
        }
        
        return maxHeap.size();
    }
};