//leetcode.com/problems/substring-with-largest-variance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        vector<bool> isPresent(s.length(), false);
        for (auto& _: s)
            isPresent[_ - 'a'] = true;

        int result = 0;

        for (auto first = 'a'; first <= 'z'; ++first) {
            for (auto second = 'a'; second <= 'z'; ++second) {
                if (!isPresent[first - 'a'] or !isPresent[second - 'a'])
                    continue;

                int firstCount = 0;
                int secondCount = 0;
                bool secondElementVisited = false;

                for (auto& ch: s) {
                    firstCount += (ch == first);
                    secondCount += (ch == second);

                    if (secondCount > 0) {
                        result = max(result, firstCount - secondCount);
                    } else {
                        if (secondElementVisited)
                            result = max(result, firstCount - 1);
                    }

                    if (secondCount > firstCount) {
                        firstCount = 0;
                        secondCount = 0;
                        secondElementVisited = true;
                    }
                }
            }
        }

        return result;
    }
};
