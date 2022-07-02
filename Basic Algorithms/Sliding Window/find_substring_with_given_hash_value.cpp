//leetcode.com/problems/find-substring-with-given-hash-value/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int val(char ch) {
        return ch - 'a' + 1;
    }
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long highest_power = 1;
        int p = k - 1;
        for (int i = 0; i < k - 1; ++i)
            highest_power = (highest_power * power) % modulo;
        
        int index = 0;
        long long hash = 0;
        int end = s.length() - 1;
        
        for (int start = s.length() - 1; start >= 0; --start) {
            hash = (hash * power % modulo + val(s[start])) % modulo;
            if (end - start + 1 == k) {
                if (hash == hashValue) 
                    index = start;
                hash = (hash - (val(s[end])) * highest_power % modulo + modulo) % modulo;
                --end;
            }
        }
        return s.substr(index, k);
    }
};