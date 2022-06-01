//leetcode.com/problems/three-equal-parts/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> res = {-1, -1};
        int totalOnes = accumulate(arr.begin(), arr.end(), 0);
        if (totalOnes % 3 != 0)
            return res;
        if (totalOnes == 0)
            return {0, 2};
        int firstGroupFirstOne = -1;
        int secondGroupFirstOne = -1;
        int thirdGroupFirstOne = -1;
        int totalOnesInEachGroup = totalOnes / 3;
        int onesVisited = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 1) {
                ++onesVisited;
                if (onesVisited == 1)
                    firstGroupFirstOne = i;
                if (onesVisited == totalOnesInEachGroup + 1)
                    secondGroupFirstOne = i;
                if (onesVisited == 2 * totalOnesInEachGroup + 1)
                    thirdGroupFirstOne = i;
            }
        }
        while (thirdGroupFirstOne < arr.size()) {
            if (arr[firstGroupFirstOne] == arr[secondGroupFirstOne] && arr[secondGroupFirstOne] == arr[thirdGroupFirstOne]) {
                ++firstGroupFirstOne;
                ++secondGroupFirstOne;
                ++thirdGroupFirstOne;
            } else {
                return res;
            }
        }
        res[0] = firstGroupFirstOne - 1;
        res[1] = secondGroupFirstOne;
        return res;
    }
};