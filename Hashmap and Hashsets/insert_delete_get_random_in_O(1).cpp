//leetcode.com/problems/insert-delete-getrandom-o1/

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    unordered_set<int> randomized; 
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool alreadyPresent = false;
        if (randomized.find(val) != randomized.end())
            alreadyPresent = true;
        randomized.insert(val);
        return !alreadyPresent;
    }
    
    bool remove(int val) {
        bool isPresent = false;
        if (randomized.find(val) != randomized.end()) {
            isPresent = true; 
            randomized.erase(val);
        }
        return isPresent;
    }
    
    int getRandom() {
        auto curr = randomized.begin();
        advance(curr, rand() % randomized.size());
        return *curr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */