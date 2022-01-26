#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int n, vector<int> &arr)
{
    int first = INT_MIN;
    int second = INT_MIN;
	for (int i = 0; i < n; ++i) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == INT_MIN)
        return -1;
    return second;
}