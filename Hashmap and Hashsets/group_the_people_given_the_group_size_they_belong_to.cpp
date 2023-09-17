//leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, vector<int>> getGroupSizeToPeopleMap(vector<int>& groupSizes) {
        map<int, vector<int>> groupSizeToPeopleMap;
        for (int i = 0; i < groupSizes.size(); ++i)
            groupSizeToPeopleMap[groupSizes[i]].push_back(i);
        return groupSizeToPeopleMap;
    }
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> groupSizeToPeopleMap = getGroupSizeToPeopleMap(groupSizes);
        vector<vector<int>> groups;
        
        for (auto& group: groupSizeToPeopleMap) {
            vector<int> currentGroup;
            for (auto& people: group.second) {
                if (currentGroup.size() < group.first) {
                    currentGroup.push_back(people);
                }
                if (currentGroup.size() >= group.first) {
                    groups.push_back(currentGroup);
                    currentGroup.clear();
                }
            }
        }
        
        return groups;
    }
};
