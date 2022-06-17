//leetcode.com/problems/sum-of-square-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long start = 0;
        long end = sqrt(c);
        bool is_sum_of_squares = false;
        while (start <= end) {
            if (start * start + end * end == c) {
                is_sum_of_squares = true;
                break;
            } else if (start * start + end * end < c)
                ++start;
            else
                --end;
        }
        return is_sum_of_squares;
    }
};