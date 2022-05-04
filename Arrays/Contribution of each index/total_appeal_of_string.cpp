//leetcode.com/problems/total-appeal-of-a-string/submissions/

//leetcode.com/problems/total-appeal-of-a-string/discuss/1997337/Pictorial-explanation-linear-solution.-Question-with-similar-approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long appealSum(string s) {
        vector<int> lastOccurence(26, -1);
        long long appeal_of_string = 0;
        for (int i = 0; i < s.length(); ++i) {
            appeal_of_string += (s.length() - i) * (i - lastOccurence[s[i] - 'a']);
            lastOccurence[s[i] - 'a'] = i;
        }
        return appeal_of_string;
    }
};