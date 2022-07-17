//leetcode.com/problems/find-the-winner-of-the-circular-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createFriendsArray(vector<int>& friends, int n) {
        for (int i = 1; i <= n; ++i)
            friends.push_back(i);
    }
    
    int winner(vector<int>& friends, int k, int index) {
        if (friends.size() == 1)
            return friends[0];
        
        index = (index + k) % friends.size();
        friends.erase(friends.begin() + index);
        return winner(friends, k, index);
    }
    
    int findTheWinner(int n, int k) {
        if (k == 1 || n == 1)
            return n;
        vector<int> friends;
        createFriendsArray(friends, n);
        --k;
        return winner(friends, k, 0);
    }
};