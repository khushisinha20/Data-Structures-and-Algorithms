//leetcode.com/problems/maximum-score-words-formed-by-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidWord(string& word, vector<int>& freq) {
        bool flag = true;
        for (int i = 0; i < word.length(); ++i) {
            if (freq[word[i] - 'a'] == 0)
                flag = false;
            --freq[word[i] - 'a'];
        }
        return flag;
    }
    
    int getScore(string& word, vector<int>& score) {
        int word_score = 0;
        for (int i = 0; i < word.length(); ++i) {
            word_score += score[word[i] - 'a'];
        }
        return word_score;
    }
    
    int findMaxScore(vector<string>& words, vector<char>& letters, vector<int>& score, vector<int>& freq, int index) {
        if (index == words.size())
            return 0; 
        
        int score_by_not_including = findMaxScore(words, letters, score, freq, index + 1);
        int score_by_including = 0;
        if (isValidWord(words[index], freq)) {
            int word_score = getScore(words[index], score);
            score_by_including = word_score + findMaxScore(words, letters, score, freq, index + 1);
        }
        for (int i = 0; i < words[index].length(); ++i) {
            ++freq[words[index][i] - 'a'];
        }
        return max(score_by_including, score_by_not_including);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for (int i = 0; i < letters.size(); ++i)
            ++freq[letters[i] - 'a'];
        return findMaxScore(words, letters, score, freq, 0);
    }
};