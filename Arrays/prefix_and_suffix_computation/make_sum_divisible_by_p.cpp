#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % p == 0)
            return 0;
        sum = sum % p;
        long long currSum = 0;
        long long result = INT_MAX;
        unordered_map<long long, long long> mp;
        mp[0] = -1;
        for (long long i = 0; i < nums.size(); ++i) {
            currSum = (currSum + nums[i]) % p;
            long long prevSum = (currSum - sum + p) % p;
            if (mp.find(prevSum) != mp.end()) {
                result = min(result, i - mp[prevSum]);
            }
            mp[currSum] = i;
        }
        return result == nums.size() ? -1 : result;
    }
};