//leetcode.com/problems/making-file-names-unique/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> existingFolderNames;
        int n = names.size();
        vector<string> ans(n);
        char openingBracket = '(';
        char closingBracket = ')';
        
        for (int i = 0; i < n; ++i) {
            string name = names[i];
            if (existingFolderNames.count(name)) {
                int count = existingFolderNames[name];
                string key = name + openingBracket + to_string(count) + closingBracket;
                while (existingFolderNames.find(key) != existingFolderNames.end()) {
                    ++count;
                    key = name + openingBracket + to_string(count) + closingBracket;
                }
                existingFolderNames[name] = count;
                existingFolderNames[key] = 1; 
                ans[i] = key;
            } else {
                existingFolderNames[name] = 1; 
                ans[i] = name;
            }
        }
        
        return ans;
    }
};
