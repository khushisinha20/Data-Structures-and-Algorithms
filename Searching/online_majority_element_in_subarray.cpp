//leetcode.com/problems/online-majority-element-in-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class MajorityChecker {
public:
    vector<int> arr;
    unordered_map<int, vector<int>> indices;

    MajorityChecker(vector<int>& arr) {
        this -> arr = arr;
        for (int i = 0; i < arr.size(); ++i) {
            indices[arr[i]].push_back(i);
        }
    }

    int countInRange(int num, int left, int right) {
        auto& index = indices[num];
        auto itLeft = lower_bound(index.begin(), index.end(), left);
        auto itRight = upper_bound(index.begin(), index.end(), right);
        return itRight - itLeft;
    }
    
    int query(int left, int right, int threshold) {
        for (int i = 0; i < 20; ++i) {
            int candidate = arr[left + rand() % (right - left + 1)];
            if (countInRange(candidate, left, right) >= threshold)
                return candidate;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
