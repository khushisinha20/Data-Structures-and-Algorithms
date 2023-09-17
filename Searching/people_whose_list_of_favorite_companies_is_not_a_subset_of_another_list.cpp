//leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubset(const unordered_set<string>& set1, const unordered_set<string>& set2) {
        for (const string& company : set1) {
            if (set2.find(company) == set2.end()) {
                return false;
            }
        }
        return true;
    }

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<unordered_set<string>> favoriteCompaniesSet;

        for (const vector<string>& person : favoriteCompanies) {
            unordered_set<string> companies(person.begin(), person.end());
            favoriteCompaniesSet.push_back(companies);
        }

        vector<int> result;

        for (int i = 0; i < favoriteCompaniesSet.size(); ++i) {
            bool isDistinct = true;
            for (int j = 0; j < favoriteCompaniesSet.size(); ++j) {
                if (i != j && favoriteCompaniesSet[j].size() > favoriteCompaniesSet[i].size() && isSubset(favoriteCompaniesSet[i], favoriteCompaniesSet[j])) {
                    isDistinct = false;
                    break;
                }
            }

            if (isDistinct) {
                result.push_back(i);
            }
        }

        return result;
    }
};