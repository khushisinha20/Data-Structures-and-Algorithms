//leetcode.com/problems/swap-adjacent-in-lr-string/

//Using extra space

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillPositions(vector<pair<char, int>>& positions, string& s) {
        for (int i = 0; i < s.length(); ++i)
            if (s[i] != 'X')
                positions.push_back({s[i], i});
    }
    
    bool areCharactersSame(char a, char b, char swappable_element) {
        return a == b && b == swappable_element;
    }
    
    bool canTransform(string start, string end) {
        vector<pair<char, int>> LR_in_start;
        vector<pair<char, int>> LR_in_end;
        fillPositions(LR_in_start, start);
        fillPositions(LR_in_end, end);
        
        if (LR_in_start.size() != LR_in_end.size())
            return false;
        
        for (int i = 0; i < LR_in_end.size(); ++i) {
            if (areCharactersSame(LR_in_start[i].first, LR_in_end[i].first, 'L')) {
                if (LR_in_start[i].second < LR_in_end[i].second)
                    return false;
            } else if (areCharactersSame(LR_in_start[i].first, LR_in_end[i].first, 'R')) {
                if (LR_in_start[i].second > LR_in_end[i].second)
                    return false;
            } else {
                return false;   
            }
        }
        return true;
    }
};
