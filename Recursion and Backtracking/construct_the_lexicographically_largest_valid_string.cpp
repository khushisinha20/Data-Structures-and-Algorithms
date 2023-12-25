//leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& result, vector<bool>& used, int& n, int index, bool& success) {
        if (index == result.size()) {
            success = true;
            return;
        }
        
        if (result[index] != 0) {
            backtrack(result, used, n, index + 1, success);
            return;
        }
        
        for (int num = n; num >= 1; --num) {
            if (used[num])
                continue;
            int nextIndex = index + num;
            
            if (num != 1 and (nextIndex >= result.size() or result[nextIndex] != 0))
                continue;
            
            used[num] = true;
            result[index] = num;
            if (num != 1)
                result[nextIndex] = num;
            backtrack(result, used, n, index + 1, success);
            
            if (success)
                return;
            
            result[index] = 0;
            used[num] = false;
            if (num != 1)
                result[nextIndex] = 0;
        }
    }
    
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        bool success = false;
        backtrack(result, used, n, 0, success);
        return result;
    }
};