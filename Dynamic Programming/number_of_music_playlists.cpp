//leetcode.com/problems/number-of-music-playlists/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long N;
    long long K;
    long long GOAL;
    const int MOD = 1e9 + 7;
    long long dp[101][101];
    
    long long helper(int songCount, int uniqueSongCount) {
        if (songCount == GOAL)
            return uniqueSongCount == N;
        
        if (dp[songCount][uniqueSongCount] != -1)
            return dp[songCount][uniqueSongCount];
        
        long long result = 0;
        if (N - uniqueSongCount > 0)
            result += (N - uniqueSongCount) * helper(songCount + 1, uniqueSongCount + 1);
        
        if (uniqueSongCount - K > 0)
            result += (uniqueSongCount - K) * helper(songCount + 1, uniqueSongCount);
        
        return dp[songCount][uniqueSongCount] = result % MOD;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        N = n;
        GOAL = goal;
        K = k;
        memset(dp, -1, sizeof dp);
        return helper(0, 0);
    }
};