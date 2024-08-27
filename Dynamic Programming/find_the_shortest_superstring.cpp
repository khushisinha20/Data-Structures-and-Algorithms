//leetcode.com/problems/find-the-shortest-superstring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getKey(const string& s, int mask) {
        char DELIMETER = '-';
        return s + DELIMETER + to_string(mask);
    }

    bool isConsumed(int mask, int index) {
        return ((mask >> index) & 1) == 0;
    }

    int consume(int mask, int index) {
        return mask & ~(1 << index);
    }

    string overlapAppend(const string& a, const string& b) {
        for (int i = max(1, (int)(a.length() - b.length())); i < a.length(); ++i) {
            bool match = true;
            for (int j = i; j < a.length(); j++) {
                if (a[j] != b[j - i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                return a.substr(0, i) + b;
            }
        }

        return a + b;
    }

    string helper(vector<string>& words, string startWord, int currentMask, unordered_map<string, string>& memo) {
        static int n = words.size();
        static int allUsedMask = 0;

        if (currentMask == allUsedMask)
            return startWord;

        string key = getKey(startWord, currentMask);
        if (memo.find(key) != memo.end())
            return memo[key];

        string shortest;
        for (int i = 0; i < words.size(); ++i) {
            if (!isConsumed(currentMask, i)) {
                string superstring = helper(words, words[i], consume(currentMask, i), memo);
                string appended = overlapAppend(startWord, superstring);

                if (shortest.empty() || appended.length() < shortest.length())
                    shortest = appended;
            }
        }

        return memo[key] = shortest;
    }

    string shortestSuperstring(vector<string>& words) {
        unordered_map<string, string> memo;
        int initialMask = (1 << words.size()) - 1;
        return helper(words, "", initialMask, memo);
    }
};
