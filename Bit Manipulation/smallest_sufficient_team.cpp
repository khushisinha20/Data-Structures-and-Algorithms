#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/smallest-sufficient-team/

class Solution {
public:
    int totalSkills;
    
    unordered_map<string, int> mapSkillsToIndex(vector<string>& skills) {
        unordered_map<string, int> skillIndex;
        for (int i = 0; i < skills.size(); ++i)
            skillIndex[skills[i]] = i;
        return skillIndex;
    }
    
    vector<int> getSkillMasks(unordered_map<string, int>& skillIndex, vector<vector<string>>& people) {
        vector<int> skillMasks(people.size(), 0);
        for (int i = 0; i < people.size(); ++i) {
            for (int j = 0; j < people[i].size(); ++j) {
                skillMasks[i] |= 1 << skillIndex[people[i][j]];
            }
        }
        return skillMasks;
    }
    
    void dfs(vector<int>& result, vector<int>& current, vector<int>& skillMasks, int currentMask, int index) {
        if (currentMask == ((1 << totalSkills) - 1)) {
            if (result.empty() or current.size() < result.size()) {
                result = current;
            }
            return;
        }
        
        if (index == skillMasks.size())
            return;
        
        if (!result.empty() and current.size() >= result.size())
            return;
        
        if ((currentMask | skillMasks[index]) != currentMask) {
            current.push_back(index);
            dfs(result, current, skillMasks, currentMask | skillMasks[index], index + 1);
            current.pop_back();
        }
        
        dfs(result, current, skillMasks, currentMask, index + 1);
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        auto skillIndex = mapSkillsToIndex(req_skills);
        auto skillMasks = getSkillMasks(skillIndex, people); 
        totalSkills = req_skills.size();
        vector<int> result;
        vector<int> current;
        dfs(result, current, skillMasks, 0, 0);
        return result;
    }
};