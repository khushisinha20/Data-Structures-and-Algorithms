//leetcode.com/problems/maximum-good-people-based-on-statements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string& personTypes, vector<vector<int>>& statements) {
        int n = statements.size();

        for (int i = 0; i < n; ++i){
            if (personTypes[i] == '1'){
                for (int j = 0; j < n; ++j){
                    if (statements[i][j] != 2 and statements[i][j] != personTypes[j] - '0')
                        return false;
                }
            }
        }

        return true;
    }

    void dfs(vector<vector<int>>& statements, string& personTypes, int index, int goodPersonCount, int& result) {
        int n = statements.size();
        if (index == n) {
            if (isValid(personTypes, statements))
                result = max(result, goodPersonCount);
            return;
        }

        personTypes.push_back('1');
        dfs(statements, personTypes, index + 1, goodPersonCount + 1, result);
        personTypes.pop_back();

        personTypes.push_back('0');
        dfs(statements, personTypes, index + 1, goodPersonCount, result);
        personTypes.pop_back();
    }

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        string personTypes = "";
        int result = 0;
        dfs(statements, personTypes, 0, 0, result);
        return result;
    }
};
