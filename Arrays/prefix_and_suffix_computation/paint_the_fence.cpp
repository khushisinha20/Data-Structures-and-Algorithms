//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381869?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int paintTheFence(vector<vector<int>>& ranges, int n, int q) {
    vector<int> fence(n + 2, 0);
    for (int i = 0; i < ranges.size(); ++i) {
        int left = ranges[i][0];
        int right = ranges[i][1];
        fence[left] +=1;
        fence[right + 1] -= 1;
    }
    //vector<int> painted_fence;
    for (int i = 1; i <= n; ++i) {
        fence[i] += fence[i - 1];
    }
    int sum = 0;
    int painted_at_least_once = 0;
    for (int i = 1; i <= n; ++i) {
        if (fence[i] >= 1) {
            ++painted_at_least_once;
        }
        sum += fence[i];
    }
    if (painted_at_least_once == n && sum-2 >= n)
        return n;
    else
        return min(painted_at_least_once, sum - 2);
}
