//leetcode.com/problems/longest-absolute-file-path/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLength = 0;
        unordered_map<int, int> pathLength;
        pathLength[0] = 0;
        istringstream ss(input);
        string line;
        
        while (getline(ss, line)) {
            int depth = line.find_last_of('\t') + 1;
            string name = line.substr(depth);
            if (name.find('.') != string :: npos) {
                maxLength = max(maxLength, pathLength[depth] + (int)name.length());
            } else {
                pathLength[depth + 1] = pathLength[depth] + (int)name.length() + 1;
            }
        }
        
        return maxLength;
    }
};