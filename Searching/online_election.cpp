//leetcode.com/problems/online-election/

#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
public:
    vector<pair<int, int>> timeRecord;
    unordered_map<int, int> voteCountRecord;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxVotedPerson = -1;
        int maxVotes = 0;
        
        for (int i = 0; i < persons.size(); ++i) {
            ++voteCountRecord[persons[i]];
            if (voteCountRecord[persons[i]] >= maxVotes) {
                maxVotedPerson = persons[i];
                maxVotes = voteCountRecord[persons[i]];
                timeRecord.push_back({times[i], maxVotedPerson});
            }
        }
    }
    
    int q(int t) {
        int low = 0;
        int high = timeRecord.size() - 1;
        int currentLeader = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (timeRecord[mid].first <= t) {
                currentLeader = timeRecord[mid].second;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        
        return currentLeader;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */