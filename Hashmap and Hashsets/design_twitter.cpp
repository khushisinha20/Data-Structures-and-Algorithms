//leetcode.com/problems/design-twitte

#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int tweetCount = 0;
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    unordered_map<int, set<int>> followerToFolloweeMap;
    
    Twitter() {
        followerToFolloweeMap.clear();
        tweetCount = 0;
        maxHeap = priority_queue<pair<int, pair<int, int>>>();
    }
    
    void postTweet(int userId, int tweetId) {
        maxHeap.push({++tweetCount, {userId, tweetId}});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        auto userTimeline = maxHeap;
        int newsCount = 0;
        while (!userTimeline.empty() and newsCount < 10) {
            auto topTweet = userTimeline.top();
            userTimeline.pop();
            int postAuthorId = topTweet.second.first;
            int tweetId = topTweet.second.second;
            if (postAuthorId == userId or followerToFolloweeMap[userId].count(postAuthorId)) {
                newsFeed.push_back(tweetId);
                ++newsCount;
            }
        }
        
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followerToFolloweeMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerToFolloweeMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */