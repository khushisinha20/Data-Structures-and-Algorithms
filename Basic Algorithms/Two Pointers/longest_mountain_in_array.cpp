//leetcode.com/problems/longest-mountain-in-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        int i = 0;
        while (i < arr.size() - 1) {
            while (i < arr.size() - 1 && arr[i] == arr[i + 1]) {
                ++i;
            }
            int up = 1;
            int down = 0;
            while (i < arr.size() - 1 && arr[i] < arr[i + 1]) {
                ++up;
                ++i;
            }
            while (i < arr.size() - 1 && arr[i] > arr[i + 1]) {
                ++down;
                ++i;
            }
            if (up + down >= 3 && up > 1 && down > 0) {
                res = max(res, up + down);
            }
        }
        return res;
    }
};