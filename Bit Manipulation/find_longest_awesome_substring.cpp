//leetcode.com/problems/find-longest-awesome-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> firstOccurence;
        firstOccurence[0] = -1;
        int maxLength = 0;
        int mask = 0;

        for (int i = 0; i < s.length(); ++i) {
            int digit = s[i] - '0';
            mask ^= (1 << digit);

            if (firstOccurence.find(mask) != firstOccurence.end())
                maxLength = max(maxLength, i - firstOccurence[mask]);
            else
                firstOccurence[mask] = i;

            for (int j = 0; j < 10; ++j) {
                int newMask = mask ^ (1 << j);
                if (firstOccurence.find(newMask) != firstOccurence.end())
                    maxLength = max(maxLength, i - firstOccurence[newMask]);
            }
        }

        return maxLength;
    }
};
