//leetcode.com/problems/removing-stars-from-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> characters;
        char STAR = '*';
        for (auto character: s) {
            if (character != STAR)
                characters.push(character);
            else
                characters.pop();
        }
        string res;
        while (!characters.empty()) {
            res += characters.top();
            characters.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};