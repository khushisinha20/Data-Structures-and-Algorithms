//https://leetcode.com/problems/xor-queries-of-a-subarray
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int prefixXOR[arr.size()];
        prefixXOR[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }
        vector<int> answer;
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0)
                answer.push_back(prefixXOR[r]);
            else
                answer.push_back(prefixXOR[r] ^ prefixXOR[l - 1]);
        }
        return answer;
    }
};