//leetcode.com/problems/maximum-equal-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, int> getFrequency(vector<int>& nums) {
        map<int, int> freq;
        for (int& num: nums)
            ++freq[num];
        return freq;
    }

    int maxEqualFreq(vector<int>& nums) {
        map<int, int> freq = getFrequency(nums);
        vector<int> frequencyValues;
        for (auto& entry: freq)
            frequencyValues.push_back(entry.second);

        map<int, int> freqOfFreq = getFrequency(frequencyValues);
        int n = nums.size();
        int ans = 1;
        bool found = false;

        for (int i = n - 1; i >= 0; --i) {
            if (freqOfFreq.size() == 2) {
                int minKey = -1;
                int minValue = -1;
                int maxKey = -1;
                int maxValue = -1;
                for (auto& entry: freqOfFreq) {
                    if (minKey == -1) {
                        minKey = entry.first;
                        minValue = entry.second;
                    } else {
                        maxKey = entry.first;
                        maxValue = entry.second;
                    }
                }

                if ((maxKey - minKey == 1 and maxValue == 1) or (minKey == 1 and minValue == 1)) {
                    ans = i + 1;
                    break;
                }
            } else if (freqOfFreq.size() == 1) {
                for (auto& entry: freqOfFreq) {
                    if (entry.first == 1) {
                        ans = i + 1;
                        found = true;
                    } else {
                        if (entry.second == 1) {
                            ans = i + 1;
                            found = true;
                        }
                    }
                }
            }

            if (found)
                break;

            --freqOfFreq[freq[nums[i]]];
            if (freqOfFreq[freq[nums[i]]] == 0)
                freqOfFreq.erase(freq[nums[i]]);
            --freq[nums[i]];
            if (freq[nums[i]] == 0)
                freq.erase(nums[i]);
            else
                ++freqOfFreq[freq[nums[i]]];
        }

        return ans;
    }
};
