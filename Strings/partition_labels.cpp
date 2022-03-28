//leetcode.com/problems/partition-labels/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partition_sizes;
        unordered_map<char, int> last_index;
        for (int i = 0; i < s.length(); ++i)
            last_index[s[i]] = i;
        int partition_length = 0;
        int last = last_index[s[0]];
        for (int i = 0; i < s.length(); ++i) {
            last = max(last, last_index[s[i]]);
            if (i == last) {
                partition_sizes.push_back(partition_length + 1);
                partition_length = 0;
            } else {
                ++partition_length;
            }
        }
        return partition_sizes;
    }
};