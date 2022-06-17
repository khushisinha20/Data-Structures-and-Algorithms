//leetcode.com/problems/count-the-hidden-sequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long current_sum = 0;
        long long minimum = 0;
        long long maximum = 0;
        
        for (int i = 0; i < differences.size(); ++i) {
            current_sum += differences[i];
            minimum = min(minimum, current_sum);
            
            maximum = max(maximum, current_sum);
        
        }
        return max((long long)0, ((minimum - lower) - (maximum - upper) + 1));
    }
};