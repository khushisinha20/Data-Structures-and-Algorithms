//leetcode.com/problems/find-smallest-letter-greater-than-target/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back())
            return letters[0];
        
        int low = 0;
        int high = letters.size() - 1;
        char res;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] <= target) 
                low = mid + 1;
            else {
                res = letters[mid];
                high = mid - 1;
            }
        }
        return res;
    }
};