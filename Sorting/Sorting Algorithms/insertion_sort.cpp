//Time Complexity: O(n ^ 2)

//Stable

//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 and arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
};