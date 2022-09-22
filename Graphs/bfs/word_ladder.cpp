//leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> words;
        words.push({beginWord, 1});
        unordered_set<string> unprocessedWords(wordList.begin(), wordList.end());
        unprocessedWords.erase(beginWord);
        
        while (!words.empty()) {
            string currentWord = words.front().first;
            int steps = words.front().second;
            words.pop();
            
            if (currentWord == endWord)
                return steps;
            
            for (int i = 0; i < currentWord.length(); ++i) {
                char originalLetter = currentWord[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    currentWord[i] = j;
                    if (unprocessedWords.find(currentWord) != unprocessedWords.end()) {
                        unprocessedWords.erase(currentWord);
                        words.push({currentWord, steps + 1});
                    }
                }
                currentWord[i] = originalLetter;
            }
        }
        return 0;
    }
};