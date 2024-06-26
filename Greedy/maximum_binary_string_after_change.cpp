//leetcode.com/problems/maximum-binary-string-after-change/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int previous = 0;
        while (previous < binary.length() and binary[previous] == '1')
            ++previous;

        int zeroes = 0;
        int ones = 0;
        for (int i = previous; i < binary.length(); ++i) {
            ones += binary[i] == '1';
            zeroes += binary[i] == '0';
        }

        for (int i = previous; i < binary.length(); ++i) {
            if (zeroes > 1) {
                binary[i] = '1';
                --zeroes;
            } else if (zeroes == 1) {
                binary[i] = '0';
                --zeroes;
            } else
                binary[i] = '1';
        }

        return binary;
    }
};
