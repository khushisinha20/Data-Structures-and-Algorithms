//leetcode.com/problems/longest-subsequence-repeated-k-times/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string sub, string s, int k) {
        int j = 0, count = 0;
        for (char c : s) {
            if (c == sub[j]) {
                j++;
                if (j == sub.size()) {
                    ++count;
                    j = 0;
                    if (count == k)
                        return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> states;
        states.push("");
        string ans = "";

        while (!states.empty()) {
            int size = states.size();
            for (int i = 0; i < size; ++i) {
                string current = states.front();
                states.pop();
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (isValid(current + c, s, k)) {
                        ans = current + c;
                        states.push(current + c);
                    }
                }
            }
        }

        return ans;
    }
};

