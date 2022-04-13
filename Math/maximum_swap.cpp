//leetcode.com/problems/maximum-swap/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        unordered_map<int, int> last_occurence;
        for (int i = 0; i < n.length(); ++i) {
            last_occurence[n[i] - '0'] = i;
        }
        for (int i = 0; i < n.length(); ++i) {
            for (int j = 9; j > n[i] - '0'; --j) {
                if (last_occurence[j] > i) {
                    swap(n[last_occurence[j]], n[i]);
                    return stoi(n);
                }
            } 
        }
        return stoi(n);
    }
};