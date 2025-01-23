//leetcode.com/problems/lfu-cache/description/

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    int capacity;
    int minFrequency;
    unordered_map<int, pair<int, int>> keyValueMap;
    unordered_map<int, list<int>::iterator> keyIteratorMap;
    unordered_map<int, list<int>> frequencyMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFrequency = 0;
    }

    void makeFrequentlyUsed(int key) {
        int frequency = keyValueMap[key].second;
        frequencyMap[frequency].erase(keyIteratorMap[key]);
        if (frequencyMap[frequency].empty()) {
            frequencyMap.erase(frequency);
            if (minFrequency == frequency) {
                ++minFrequency;
            }
        }
        ++frequency;
        keyValueMap[key].second = frequency;
        frequencyMap[frequency].push_front(key);
        keyIteratorMap[key] = frequencyMap[frequency].begin();
    }

    int get(int key) {
        if (keyValueMap.find(key) != keyValueMap.end()) {
            makeFrequentlyUsed(key);
            return keyValueMap[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyValueMap.find(key) != keyValueMap.end()) {
            keyValueMap[key].first = value;
            makeFrequentlyUsed(key);
            return;
        }

        if (keyValueMap.size() >= capacity) {
            int evictKey = frequencyMap[minFrequency].back();
            frequencyMap[minFrequency].pop_back();
            if (frequencyMap[minFrequency].empty()) {
                frequencyMap.erase(minFrequency);
            }
            keyValueMap.erase(evictKey);
            keyIteratorMap.erase(evictKey);
        }

        minFrequency = 1;
        keyValueMap[key] = {value, 1};
        frequencyMap[1].push_front(key);
        keyIteratorMap[key] = frequencyMap[1].begin();
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
