//leetcode.com/problems/count-the-repetitions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length();
        int len2 = s2.length();
        unordered_map<int, pair<int, int>> stateMap;
        int s1Count = 0;
        int s2Count = 0;
        int s2Index = 0;

        while (s1Count < n1) {
            ++s1Count;
            for (char c: s1) {
                if (c == s2[s2Index]) {
                    ++s2Index;
                    if (s2Index == len2) {
                        s2Index = 0;
                        ++s2Count;
                    }
                }
            }

            if (stateMap.find(s2Index) != stateMap.end()) {
                auto [prevS1Count, prevS2Count] = stateMap[s2Index];
                int cycleLength = s1Count - prevS1Count;
                int cycleS2Count = s2Count - prevS2Count;

                int remainingS1 = n1 - s1Count;
                int fullCycles = remainingS1 / cycleLength;

                s1Count += fullCycles * cycleLength;
                s2Count += fullCycles * cycleS2Count;
            } else {
                stateMap[s2Index] = {s1Count, s2Count};
            }
        }

        return s2Count / n2;
    }
};
