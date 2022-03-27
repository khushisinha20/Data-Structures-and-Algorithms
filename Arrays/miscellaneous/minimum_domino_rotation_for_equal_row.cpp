#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> domino_frequency(8, 0);
        vector<int> top_frequency(8, 0);
        vector<int> bottom_frequency(8, 0);
        int min_domino_rotations = INT_MAX;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] == bottoms[i]) {
                ++domino_frequency[tops[i]];
                ++top_frequency[tops[i]];
                ++bottom_frequency[bottoms[i]];
            } else {
                ++domino_frequency[tops[i]];
                ++domino_frequency[bottoms[i]];
                ++top_frequency[tops[i]];
                ++bottom_frequency[bottoms[i]];
            }
        }
        bool areAllDominosAvailable = false;
        for (int i = 1; i < 7; ++i) {
            if (domino_frequency[i] == tops.size()) {
                areAllDominosAvailable = true;
                min_domino_rotations = min(min_domino_rotations, (n - max(top_frequency[i], bottom_frequency[i])));
            }
        }
        if (areAllDominosAvailable)
            return min_domino_rotations;
        return -1;
    }
};