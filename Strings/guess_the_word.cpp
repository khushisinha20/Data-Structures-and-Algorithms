//leetcode.com/problems/guess-the-word/

#include <bits/stdc++.h>
using namespace std;

class Master {
  public:
    int guess(string word);
};

class Solution {
public:
    int findMatches(string& a, string& b) {
        int matches = 0;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] == b[i])
                ++matches;
        return matches;
    }
    
    void findNewCandidates(vector<string>& newCandidates, vector<string>& candidates, string& word, int& matches) {
        for (auto candidate: candidates)
            if (findMatches(candidate, word) == matches)
                newCandidates.push_back(candidate);
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(0));
        vector<string> candidates(wordlist.begin(), wordlist.end());
        
        while (!candidates.empty()) {
            string word = candidates[rand() % candidates.size()];
            int matches = master.guess(word);
            if (matches == 6)
                return;
            vector<string> newCandidates;
            findNewCandidates(newCandidates, candidates, word, matches);
            candidates = newCandidates;
        }
    }
};