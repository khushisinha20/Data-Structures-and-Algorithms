//leetcode.com/problems/find-duplicate-file-in-system/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hash;
        
        for (auto& path: paths) {
            stringstream ss(path);
            string dir;
            string file;
            
            getline(ss, dir, ' ');
            while (getline(ss, file, ' ')) {
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(') - 1);
                string name = dir + '/' + file.substr(0, file.find('('));
                hash[content].push_back(name);
            }
        }
        
        vector<vector<string>> result;
        
        for (auto i = hash.begin(); i != hash.end(); ++i) {
            if (i -> second.size() > 1)
                result.push_back(i -> second);
        }
        
        return result;
    }
};