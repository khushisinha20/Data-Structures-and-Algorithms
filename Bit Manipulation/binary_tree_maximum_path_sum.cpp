//leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMask(vector<int>& mask, vector<int>& parent, string& s, int node) {
        if (node > 0 and mask[node] == 0)
            mask[node] = getMask(mask, parent, s, parent[node]) ^ (1 << (s[node] - 'a'));
        return mask[node];
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        long long result = 0;
        vector<int> mask(n, 0);
        unordered_map<int, int> maskCount;
        maskCount[0] = 1;

        for (int i = 1; i < n; ++i) {
            int currentMask = getMask(mask, parent, s, i);
            for (int j = 0; j < 26; ++j) {
                result += maskCount[currentMask ^ (1 << j)];
            }
            result += maskCount[currentMask]++;
        }

        return result;
    }
};
