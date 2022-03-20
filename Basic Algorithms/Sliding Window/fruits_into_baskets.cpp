//leetcode.com/problems/fruit-into-baskets/submissions/

#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;
        int max_fruits = 0;
        unordered_map<int,int> mp;
        for (int end = 0; end < fruits.size(); ++end) {
            ++mp[fruits[end]];
            if (mp.size() <= 2) {
                max_fruits = max(max_fruits, end - start + 1);
            }
            while (mp.size() > 2) {
                --mp[fruits[start]];
                if (mp[fruits[start]] == 0)
                    mp.erase(fruits[start]);
                ++start;
            }
        }
        return max_fruits;
    }
};