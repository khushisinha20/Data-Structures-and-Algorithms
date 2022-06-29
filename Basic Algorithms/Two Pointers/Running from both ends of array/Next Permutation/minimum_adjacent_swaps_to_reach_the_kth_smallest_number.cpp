//leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(string& s) {
        int less_than_next = -1;
        for (int i = s.length() - 2; i >= 0; --i) {
            if (s[i] < s[i + 1]) {
                less_than_next = i;
                break;
            }
        }
        if (less_than_next == -1) 
            return;
        int idx = -1;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[less_than_next] < s[i]) {
                idx = i;
                break;
            }
        }
        swap(s[less_than_next], s[idx]);
        reverse(s.begin() + less_than_next + 1, s.end());
    }
    
    int getMinSwaps(string num, int k) {
        string s = num;
        int res = 0;
        while (k--)
            nextPermutation(num);
        for (int i = 0; i < num.length(); ++i) {
            if (num[i] != s[i]) {
                int j = i + 1;
                while (num[j] != s[i]) 
                    ++j;
                while (j > i) {
                    swap(num[j], num[j - 1]);
                    --j;
                    ++res;
                }
            }
        }
        return res;
    }
};