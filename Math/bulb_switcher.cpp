//leetcode.com/problems/bulb-switcher/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int on_bulbs = 0;
        for (int i = 1; i * i <= n; ++i) {
            ++on_bulbs;
        }
        return on_bulbs;
    }
};
