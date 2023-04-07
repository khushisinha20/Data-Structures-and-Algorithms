//leetcode.com/problems/rle-iterator/

#include <bits/stdc++.h>
using namespace std;

class RLEIterator {
public:
    long long index;
    vector<long long> prefixSum;
    vector<long long> value;
        
    RLEIterator(vector<int>& encoding) {
        long long sum = 0;
        
        for (int i = 0; i < encoding.size(); ++i) {
            if (i % 2 == 0 and encoding[i] != 0) {
                sum += (long long)encoding[i];
                prefixSum.push_back(sum);
                value.push_back((long long)encoding[i + 1]);
            }
        }
        
        index = 0;
    }
    
    int next(int n) {
        index += n;
        auto iterator = lower_bound(prefixSum.begin(), prefixSum.end(), index);
        if (iterator == prefixSum.end())
            return -1;
        return value[iterator - prefixSum.begin()];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
