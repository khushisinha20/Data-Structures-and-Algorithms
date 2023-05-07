//leetcode.com/problems/dota2-senate/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillSenators(queue<int>& senators, char party, string& senate) {
        for (int i = 0; i < senate.length(); ++i)
            if (senate[i] == party)
                senators.push(i);
    }
    
    string predictPartyVictory(string senate) {
        queue<int> radiantSenators;
        queue<int> direSenators;
        fillSenators(radiantSenators, 'R', senate);
        fillSenators(direSenators, 'D', senate);
        
        while (!radiantSenators.empty() and !direSenators.empty()) {
            int currentRadiant = radiantSenators.front();
            int currentDire = direSenators.front();
            radiantSenators.pop();
            direSenators.pop();
            
            currentRadiant < currentDire ? radiantSenators.push(currentRadiant + senate.length()) : direSenators.push(currentDire + senate.length());
        }
        
        return radiantSenators.size() > direSenators.size() ? "Radiant" : "Dire";
    }
};