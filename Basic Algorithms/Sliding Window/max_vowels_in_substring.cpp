//leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int maxVowels(string s, int k) {
        int start = 0;
        int vowels = 0;
        int maximum_vowels = 0;
        for (int end = 0; end < s.length(); ++end) {
            if (isVowel(s[end]))
                ++vowels;
            if (end - start + 1 == k) {
                maximum_vowels = max(maximum_vowels, vowels);
                if (isVowel(s[start]))
                    --vowels;
                ++start;
            }
        }
        return maximum_vowels;
    }
};