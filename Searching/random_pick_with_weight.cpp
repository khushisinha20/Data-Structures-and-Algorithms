//leetcode.com/problems/random-pick-with-weight/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prefix_sum; 
    
    Solution(vector<int>& w) {
        prefix_sum.push_back(w[0]);
        for (int i = 1; i < w.size(); ++i)
            prefix_sum.push_back(w[i] + prefix_sum.back());
    }
    
    int pickIndex() {
        int rand_weight = rand() % (prefix_sum.back());
        return upper_bound(prefix_sum.begin(), prefix_sum.end(), rand_weight) - prefix_sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */