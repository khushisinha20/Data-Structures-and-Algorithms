//leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pushAgainIntoStack(stack<char>& characters, string& word) {
        for (int i = 0; i < word.length(); ++i)
            characters.push(word[i]);
    }
    
    string finalWordFormed(stack<char>& characters) {
        string final_word;
        while (!characters.empty()) {
            final_word += characters.top();
            characters.pop();
        }
        reverse(final_word.begin(), final_word.end());
        return final_word;
    }
    
    string reverseParentheses(string s) {
        stack<char> characters;
        string word;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')') {
                word = "";
                while (characters.top() != '(') {
                    word += characters.top();
                    characters.pop();
                }
                characters.pop();
                pushAgainIntoStack(characters, word);
            } else 
                characters.push(s[i]);
        }
        return finalWordFormed(characters);
    }
};