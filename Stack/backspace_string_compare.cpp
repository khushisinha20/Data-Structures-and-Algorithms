//leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void removeLeadingBackspaces(string& text) {
        while (text.back() == '#')
            text.pop_back(); 
    }
    
    void textAfterBackspace(string& text, stack<char>& s) {
        while (!s.empty()) {
            text.push_back(s.top());
            s.pop();
        }
        removeLeadingBackspaces(text);
        reverse(text.begin(), text.end());
    }
    
    string charactersAfterBackspace(string& s) {
        stack<char> characters;
        for (int i = 0; i < s.length(); ++i) {
            if (!characters.empty() && s[i] == '#')
                characters.pop();
            else
                characters.push(s[i]);
        }
        string final_text;
        textAfterBackspace(final_text, characters);
        return final_text;
    }
    
    bool backspaceCompare(string s, string t) {
        return charactersAfterBackspace(s) == charactersAfterBackspace(t);
    }
};