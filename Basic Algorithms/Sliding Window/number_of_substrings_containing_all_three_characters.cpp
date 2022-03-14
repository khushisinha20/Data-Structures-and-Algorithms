//leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        vector<int> seen(s.length(), -1);
        for (int i = 0; i < s.length(); ++i) {
            seen[s[i] - 'a'] = i;
            if (seen[0] == -1 || seen[1] == -1 || seen[2] == -1)
                continue;
            result += 1 + min(seen[2], min(seen[0], seen[1]));
        }
        return result;
    }
};