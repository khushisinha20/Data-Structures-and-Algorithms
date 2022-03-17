//leetcode.com/problems/maximize-the-confusion-of-an-exam/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int count_of_T = 0;
        int count_of_F = 0;
        int count_of_min = 0;
        int start = 0;
        int len = 0;
        for (int end = 0; end < answerKey.length(); ++end) {
            if (answerKey[end] == 'T')
                ++count_of_T;
            else
                ++count_of_F;
            count_of_min = min(count_of_T, count_of_F);
            if (count_of_min <= k) {
                len = max(len, end - start + 1);
            } else {
                while (count_of_min > k) {
                    answerKey[start] == 'T' ? --count_of_T : --count_of_F;
                    count_of_min = min(count_of_T, count_of_F);
                    ++start;
                }
            }
        }
        return len;
    }
};