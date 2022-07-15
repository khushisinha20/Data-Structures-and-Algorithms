//leetcode.com/problems/online-election/

#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
public:
    unordered_map<int, int> votes;
    vector<pair<int, int>> vec;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_votes = 0;
        int person_with_max_votes = 0;
        for (int i = 0; i < times.size(); ++i) {
            ++votes[persons[i]];
            if (votes[persons[i]] >= max_votes) {
                max_votes = votes[persons[i]];
                person_with_max_votes = persons[i];
            }
            vec.push_back({times[i], person_with_max_votes});
        }
    }
    
    int q(int t) {
        int low = 0;
        int high = vec.size() - 1;
        int res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first <= t) {
                res = vec[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */