//leetcode.com/problems/can-make-palindrome-from-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> prefix(n + 1, vector<int> (26, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                prefix[i + 1][j] = prefix[i][j];
            }
            ++prefix[i + 1][s[i] - 'a'];
        }

        vector<bool> result;
        for (auto& query: queries) {
            int left = query[0];
            int right = query[1];
            int k = query[2];

            int oddCount = 0;

            for (int j = 0; j < 26; ++j) {
                int count = prefix[right + 1][j] - prefix[left][j];
                if (count % 2 != 0)
                    ++oddCount;
            }

            result.push_back(oddCount / 2 <= k);
        }

        return result;
    }
};
