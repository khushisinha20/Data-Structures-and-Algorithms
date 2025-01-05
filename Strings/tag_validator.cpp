//leetcode.com/problems/tag-validator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> tags;
        for (int i = 0; i < code.length(); ) {
            if (i > 0 and tags.empty())
                return false;
            if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                i = code.find("]]>", j);
                if (i == string :: npos)
                    return false;
                i += 3;
            } else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find('>', j);
                if (i == string :: npos)
                    return false;
                string tagName = code.substr(j, i - j);
                if (tags.empty() or tags.top() != tagName)
                    return false;
                tags.pop();
                ++i;
            } else if (code[i] == '<') {
                int j = i + 1;
                i = code.find('>', j);
                if (i == string :: npos)
                    return false;
                string tagName = code.substr(j, i - j);
                if (tagName.empty() or tagName.size() > 9 or !all_of(tagName.begin(), tagName.end(), ::isupper))
                    return false;
                tags.push(tagName);
                ++i;
            } else
                ++i;
        }

        return tags.empty();
    }
};
