//leetcode.com/problems/cycle-length-queries-in-a-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;

        for (auto& query: queries) {
            int a = query[0];
            int b = query[1];
            int length = 0;

            unordered_set<int> pathA;
            while (a > 0) {
                pathA.insert(a);
                a /= 2;
            }

            while (b > 0) {
                if (pathA.count(b))
                    break;
                b /= 2;
            }

            int lca = b;
            int distanceA = 0;
            int distanceB = 0;
            a = query[0];
            b = query[1];

            while (a != lca) {
                a /= 2;
                ++distanceA;
            }

            while (b != lca) {
                b /= 2;
                ++distanceB;
            }

            result.push_back(distanceA + distanceB + 1);
        }

        return result;
    }
};
