//leetcode.com/problems/largest-palindrome-product/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1337;

    long long createPalindrome(int half) {
        string s = to_string(half);
        reverse(s.begin(), s.end());
        return stoll(to_string(half) + s);
    }

    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);

        for (int i = upper; i >= lower; --i) {
            long long palindrome = createPalindrome(i);
            for (long long j = upper; j * j >= palindrome; --j) {
                if (palindrome % j == 0) {
                    long long factor = palindrome / j;
                    if (factor <= upper and factor >= lower)
                        return palindrome % MOD;
                }
            }
        }

        return -1;
    }
};
