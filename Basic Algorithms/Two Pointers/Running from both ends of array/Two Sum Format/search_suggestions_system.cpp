//leetcode.com/problems/search-suggestions-system/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int left = 0;
        int right = products.size() - 1;
        vector<vector<string>> res;
        vector<string> temp;
        for (int i = 0; i < searchWord.length(); ++i) {
            while (left <= right && (products[left].length() <= i || products[left][i] != searchWord[i]))
                ++left;
            while (left <= right && (products[right].length() <= i || products[right][i] != searchWord[i]))
                --right;
            for (int j = 0; j < min(3, right - left + 1); ++j) 
                temp.push_back(products[left + j]);
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};