#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        char DELIMETER = '.';
        int consecutiveCount = 1;
        int aliceCount = 0;
        int bobCount = 0;
        colors += DELIMETER;
        
        for (int i = 1; i < colors.length(); ++i) {
            if (colors[i] == colors[i - 1])
                ++consecutiveCount;
            else {
                if (colors[i - 1] == 'A')
                    aliceCount += max(0, consecutiveCount - 2);
                if (colors[i - 1] == 'B')
                    bobCount += max(0, consecutiveCount - 2);
                consecutiveCount = 1;
            }
        }
        
        return aliceCount > bobCount;
    }
};