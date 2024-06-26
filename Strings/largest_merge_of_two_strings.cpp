//leetcode.com/problems/largest-merge-of-two-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge;
        int i = 0;
        int j = 0;

        while (i < word1.length() and j < word2.length()) {
            if (word1.substr(i) > word2.substr(j)) {
                merge += word1[i++];
            } else
                merge += word2[j++];
        }

        while (i < word1.length())
            merge += word1[i++];

        while (j < word2.length())
            merge += word2[j++];

        return merge;
    }
};
