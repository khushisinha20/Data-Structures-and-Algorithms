//leetcode.com/problems/the-number-of-weak-characters-in-the-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0]; 
        return a[1] > b[1];
    }
    
    bool isWeak(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] && a[1] < b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comparator);
        int weak_characters = 0;
        int max_defence = INT_MIN;
        for (int i = properties.size() - 1; i >= 0; --i) {
            if (properties[i][1] < max_defence)
                ++weak_characters;
            max_defence = max(max_defence, properties[i][1]);
        }
        return weak_characters;
    }
};