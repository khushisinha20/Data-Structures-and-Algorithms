//leetcode.com/problems/bag-of-tokens/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int start = 0;
        int end = tokens.size() - 1;
        int score = 0;
        int max_score = 0;
        while (start <= end) {
            if (power >= tokens[start]) {
                power -= tokens[start];
                ++start;
                ++score;
                max_score = max(max_score, score);
            } else if (score >= 1) {
                power += tokens[end];
                --end;
                --score;
            } else
                break;
        }
        return max_score;
    }
};