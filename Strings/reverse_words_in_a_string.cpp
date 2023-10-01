//leetcode.com/problems/reverse-words-in-a-string-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseWord(string& word) {
        int left = 0;
        int right = word.size() - 1;
        
        while (left <= right) {
            swap(word[left], word[right]);
            ++left;
            --right;
        }
    }
    
    string reverseWords(string s) {
        int start = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                start = i;
                while (i < s.length() and s[i] != ' ')
                    ++i;
                reverse(s.begin() + start, s.begin() + i);
            }
        }
        
        return s;
    }
};