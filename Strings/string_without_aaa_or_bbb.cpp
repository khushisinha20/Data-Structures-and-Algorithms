#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/string-without-aaa-or-bbb/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string result;

        while (a and b) {
            if (a > b) {
                result += "aab";
                --a;
            } else if (a < b) {
                result += "bba";
                --b;
            } else
                result += "ab";
            --a;
            --b;
        }

        while (a--)
            result += 'a';

        while (b--)
            result += 'b';

        return result;
    }
};
