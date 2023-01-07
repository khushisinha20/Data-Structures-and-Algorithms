//leetcode.com/problems/remove-comments/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> code;
        bool isPartOfComment = false;
        string currentLine = "";
        map<pair<int, int>, bool> isVisited;
        
        for (int i = 0; i < source.size(); ++i) {
            if (!isPartOfComment)
                currentLine = "";
            for (int j = 0; j < source[i].size(); ++j) {
                if (j > 0 && source[i][j] == '/' && source[i][j - 1] == '*' && isPartOfComment) {
                    if (!isVisited[{i, j - 1}] && !isVisited[{i, j}]) {
                        isPartOfComment = false;
                        isVisited[{i, j - 1}] = true;
                        isVisited[{i, j}] = true;
                        continue;
                    }
                }
                if (isPartOfComment)
                    continue;
                if (j > 0 && source[i][j] == '/' && source[i][j - 1] == '/') {
                    if (!isVisited[{i, j - 1}] && !isVisited[{i, j}]) {
                        currentLine.pop_back();
                        isVisited[{i, j - 1}] = true;
                        isVisited[{i, j}] = true;
                        break;
                    }
                }
                if (j > 0 && source[i][j] == '*' && source[i][j - 1] == '/' && !isPartOfComment) {
                    if (!isVisited[{i, j - 1}] && !isVisited[{i, j}]) {
                        currentLine.pop_back();
                        isVisited[{i, j}] = true;
                        isVisited[{i, j - 1}] = true;
                        isPartOfComment = true;
                    }
                }
                if (!isPartOfComment) {
                    currentLine += source[i][j];
                }
            }
            if (!currentLine.empty() && !isPartOfComment)
                code.push_back(currentLine);
        }
        return code;
    }
};