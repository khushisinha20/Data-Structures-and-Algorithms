//leetcode.com/problems/candy/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1)
            return 1;
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = ratings.size() - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
        }
        int res = 0;
        res = accumulate(candies.begin(), candies.end(), res);
        return res;
    }
};