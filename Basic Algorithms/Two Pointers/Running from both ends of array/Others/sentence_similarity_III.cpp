//leetcode.com/problems/sentence-similarity-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    deque<string> sentenceToWords(string& sentence) {
        sentence.push_back(' ');
        deque<string> words;
        string word = "";
        for (int i = 0; i < sentence.length(); ++i) {
            if (sentence[i] == ' ') {
                words.push_back(word);
                word.clear();
            } else
                word.push_back(sentence[i]);
        }
        return words;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> sentence1ToWords = sentenceToWords(sentence1);
        deque<string> sentence2ToWords = sentenceToWords(sentence2);
        while (sentence1ToWords.size() != 0 && sentence2ToWords.size() != 0 && (sentence1ToWords.front() == sentence2ToWords.front())) {
            sentence1ToWords.pop_front();
            sentence2ToWords.pop_front();
        }
        while (sentence1ToWords.size() != 0 && sentence2ToWords.size() != 0 && (sentence1ToWords.back() == sentence2ToWords.back())) {
            sentence1ToWords.pop_back();
            sentence2ToWords.pop_back();
        }
        return sentence1ToWords.size() == 0 || sentence2ToWords.size() == 0;
     }
};