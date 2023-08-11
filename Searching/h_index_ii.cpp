//leetcode.com/problems/h-index-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0;
        int high = citations.size() - 1;
        int n = citations.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] == n - mid)
                return citations[mid];
            else if (citations[mid] < n - mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return n - (high + 1);
    }
};