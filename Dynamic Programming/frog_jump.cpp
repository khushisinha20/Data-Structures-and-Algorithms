//www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights) {
    int previous = 0;
    int previousOfprevious = 0;

    if (n == 0)
        return 0;

    for (int i = 1; i < n; ++i) {
        int first = previous + abs(heights[i] - heights[i - 1]);
        int second = INT_MAX;
        if (i > 1)
            second = previousOfprevious + abs(heights[i] - heights[i - 2]);
        int current = min(first, second);
        previousOfprevious = previous;
        previous = current;
    }
    return previous;
}