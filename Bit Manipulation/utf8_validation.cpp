//leetcode.com/problems/utf-8-validation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remainingBytes = 0;
        
        for (int value: data) {
            if (remainingBytes == 0) {
                if ((value >> 7) == 0b0)
                    remainingBytes = 0;
                else if ((value >> 5) == 0b110)
                    remainingBytes = 1;
                else if ((value >> 4) == 0b1110)
                    remainingBytes = 2;
                else if ((value >> 3) == 0b11110)
                    remainingBytes = 3;
                else
                    return false;
            } else {
                if ((value >> 6) == 0b10)
                    --remainingBytes;
                else
                    return false;
            }
        }
        
        return remainingBytes == 0;
    }
};