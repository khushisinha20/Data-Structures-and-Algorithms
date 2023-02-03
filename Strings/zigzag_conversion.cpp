//leetcode.com/problems/zigzag-conversion/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        vector<string> transformation(numRows);
        int currentRow = 0;
        
        bool goingDown = false;
        for (auto character: s) {
            transformation[currentRow] += character;
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }
        
        string transformedString;
        
        for (auto row: transformation)
            transformedString += row;
        
        return transformedString;
    }
};
