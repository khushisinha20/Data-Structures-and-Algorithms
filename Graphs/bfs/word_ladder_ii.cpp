//leetcode.com/problems/word-ladder-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string word, string& beginWord, vector<string>& currSequence, unordered_map<string, int>& stepsToReach, vector<vector<string>>& result) {
        if (word == beginWord) {
            reverse(currSequence.begin(), currSequence.end());
            result.push_back(currSequence);
            reverse(currSequence.begin(), currSequence.end());
            return;
        }

        int steps = stepsToReach[word];
        for (int i = 0; i < word.length(); ++i) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (stepsToReach.find(word) != stepsToReach.end() && stepsToReach[word] + 1 == steps) {
                    currSequence.push_back(word);
                    dfs(word, beginWord, currSequence, stepsToReach, result);
                    currSequence.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> unprocessedWords(wordList.begin(), wordList.end());
        int len = beginWord.length();
        unordered_map<string, int> stepsToReach;
        queue<string> words;
        words.push(beginWord);
        unprocessedWords.erase(beginWord);

        int steps = 1;
        stepsToReach[beginWord] = steps;

        while (!words.empty()) {
            int sz = words.size();
            for (int k = 0; k < sz; ++k) {
                string word = words.front();
                words.pop();
                steps = stepsToReach[word];

                for (int i = 0; i < len; ++i) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (unprocessedWords.find(word) != unprocessedWords.end()) {
                            stepsToReach[word] = steps + 1;
                            words.push(word);
                            unprocessedWords.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
        }

        if (stepsToReach.find(endWord) == stepsToReach.end())
            return {};

        vector<vector<string>> result;
        vector<string> currentSequence;
        currentSequence.push_back(endWord);
        dfs(endWord, beginWord, currentSequence, stepsToReach, result);
        return result;
    }
};

