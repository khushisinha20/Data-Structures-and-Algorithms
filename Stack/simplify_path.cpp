//leetcode.com/problems/simplify-path/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> files;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/')
                continue;
            string file_name;
            while (i < path.size() && path[i] != '/') {
                file_name += path[i];
                ++i;
            }
            if (file_name == ".")
                continue;
            else if (file_name == "..") {
                if (!files.empty())
                    files.pop();
            } else
                files.push(file_name);
        }
        
        string simplified_path;
        while (!files.empty()) {
            simplified_path = "/" + files.top() + simplified_path;
            files.pop();
        }
        
        if (simplified_path.size() == 0)
            return "/";
        
        return simplified_path;
    }
};