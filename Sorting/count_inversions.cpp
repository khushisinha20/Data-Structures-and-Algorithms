//practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    
    long long countAndMerge(vector<long long>& a, int low, int mid, int high) {
        long long res = 0;
        vector<long long> left(a.begin() + low, a.begin() + mid + 1);
        vector<long long> right(a.begin() + mid + 1, a.begin() + high + 1);
        int curr_idx = low;
        int i = 0;
        int j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                a[curr_idx++] = left[i++];
            } else {
                a[curr_idx++] = right[j++];
                res += (left.size() - i);
            }
        }
        while (i < left.size())
            a[curr_idx++] = left[i++];
        while (j < right.size())
            a[curr_idx++] = right[j++];
        return res;
    }
  
    long long countInversionsAndMergeSort(vector<long long>& a, int low, int high) {
        long long res = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            res += countInversionsAndMergeSort(a, low, mid);
            res += countInversionsAndMergeSort(a, mid + 1, high);
            res += countAndMerge(a, low, mid, high);
        }
        return res;
    }
    
    long long int inversionCount(long long a[], long long n) {
        vector<long long> arr(n);    
        for (int i = 0; i < n; ++i)
            arr[i] = a[i];
        
        return countInversionsAndMergeSort(arr, 0, n - 1);
    }

};