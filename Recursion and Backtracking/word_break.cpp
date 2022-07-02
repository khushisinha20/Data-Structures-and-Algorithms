//leetcode.com/problems/word-break/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string, bool>visited;
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s == "")
            return true;
        for (int i = 0; i < wordDict.size(); ++i) {
            if (s.find(wordDict[i]) == 0) {
                string rest_of_string = s.substr(wordDict[i].size());
                if (visited.find(rest_of_string) != visited.end() && visited[rest_of_string])
                    break;
                if (wordBreak(rest_of_string, wordDict))
                    return true;
                visited[rest_of_string] = true;
            }
        }
        return false;
    }
};