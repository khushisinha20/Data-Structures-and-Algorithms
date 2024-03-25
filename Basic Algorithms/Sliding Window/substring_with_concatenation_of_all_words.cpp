//leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> frequency;
        for (auto& word: words)
            ++frequency[word];

        int totalWords = words.size();
        int wordLength = words[0].length();
        int totalLength = totalWords * wordLength;
        int n = s.length();

        vector<int> result;

        for (int i = 0; i < wordLength; ++i) {
            unordered_map<string, int> currentFrequency;
            int left = i;
            for (int j = i; j < n - wordLength + 1; j += wordLength) {
                string currentWord = s.substr(j, wordLength);

                if (frequency.find(currentWord) != frequency.end()) {
                    ++currentFrequency[currentWord];

                    while (currentFrequency[currentWord] > frequency[currentWord]) {
                        --currentFrequency[s.substr(left, wordLength)];
                        left += wordLength;
                    }

                    if (j - left + wordLength == totalLength) {
                        result.push_back(left);
                        --currentFrequency[s.substr(left, wordLength)];
                        left += wordLength;
                    }
                } else {
                    currentFrequency.clear();
                    left = j + wordLength;
                }
            }
        }

        return result;
    }
};
