#include <bits/stdc++.h>
using namespace std;

void tabulateLCS(vector<vector<int>>& dp, string& text1, string& text2) {
    int n = dp.size() - 1;
    int m = dp[0].size() - 1;
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
}

string lcs(vector<vector<int>>& dp, string& text1, string& text2) {
    int n = dp.size();
    int m = dp[0].size();
    
    int i = n;
    int j = m;
    string result;
    
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            result.push_back(text1[i - 1]);
            --i;
            --j;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) 
                --i;
            else
                --j;
        }
    } 
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string text1;
    string text2;
    cin >> text1 >> text2;
    vector<vector<int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, -1));
    tabulateLCS(dp, text1, text2);
    string result = lcs(dp, text1, text2);
    cout << result;
    return 0;
}