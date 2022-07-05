//practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        int i = 0;
        int j = 0;
        vector<int> res;
        while (i < n && j < m) {
            if (i > 0 && arr1[i] == arr1[i - 1]) {
                ++i;
                continue;
            }
            if (j > 0 && arr2[j] == arr2[j - 1]) {
                ++j;
                continue;
            }
            if (arr1[i] < arr2[j]) {
                res.push_back(arr1[i]);
                ++i;
            } else if (arr1[i] > arr2[j]) {
                res.push_back(arr2[j]);
                ++j;
            } else {
                res.push_back(arr1[i]);
                ++i;
                ++j;
            }
        }
        while (i < n) {
            if (i == 0 || i > 0 && arr1[i] != arr1[i - 1]) {
                res.push_back(arr1[i]);
            }
            ++i;
        }
        while (j < m) {
            if (j == 0 || j > 0 && arr2[j] != arr2[j - 1]) {
                res.push_back(arr2[j]);
            }
            ++j;
        }
        return res;
    }
};