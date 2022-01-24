//leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); ++i) {
            int rem = arr[i] % k; 
            if (rem < 0)
                rem += k;
            ++mp[rem];
        }
        for (int i = 0; i < arr.size(); ++i) {
            int rem = arr[i] % k;
            if (rem == 0) {
                if (mp[rem] % 2 != 0)
                    return false;
            } else if (2 * rem == k) {
                if (mp[rem] % 2 != 0)
                    return false;
            } else if (mp[rem] != mp[k - rem]) {
                return false;
            }
        }
        return true;
    }
};