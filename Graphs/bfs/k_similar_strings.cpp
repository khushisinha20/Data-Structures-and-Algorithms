//leetcode.com/problems/k_similar_strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<pair<string, int>> queue;
        unordered_set<string> visited;
        int swaps = 0;
        queue.push({s1, 0});
        visited.insert(s1);

        while (!queue.empty()) {
            int size = queue.size();
            while (size--) {
                auto [s, index] = queue.front();
                queue.pop();

                if (s == s2)
                    return swaps;

                while (index < s.length() && s[index] == s2[index])
                    ++index;

                for (int i = index + 1; i < s.length(); ++i) {
                    if (s[i] == s2[index] && s[i] != s2[i]) {
                        swap(s[index], s[i]);
                        if (visited.find(s) == visited.end()) {
                            queue.push({s, index + 1});
                            visited.insert(s);
                        }
                        swap(s[index], s[i]);
                    }
                }
            }
            ++swaps;
        }

        return swaps;
    }
};
