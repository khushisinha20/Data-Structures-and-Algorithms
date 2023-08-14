//Operates by iteratively identifying the smallest element within the unsorted section and relocating it to the start.

//Time Complexity O(n ^ 2)

//Space Complexity O(1)

//Unstable

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int minimum = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minimum])
                    minimum = j;
            }
            swap(arr[i], arr[minimum]);
        }
    }
};