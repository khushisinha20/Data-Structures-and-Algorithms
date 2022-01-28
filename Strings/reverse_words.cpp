//leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string reverse_order_words = "";
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            while (i < n && s[i] == ' ') {
                ++i;
            }
            if (i >= n) {
                break;
            }
            int j = i + 1;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            string word = s.substr(i, j - i);
            if (reverse_order_words == "") {
                reverse_order_words += word;
            } else {
                reverse_order_words = word + " " + reverse_order_words;
            }
            i = j + 1;
        }
        return reverse_order_words;
    }
};