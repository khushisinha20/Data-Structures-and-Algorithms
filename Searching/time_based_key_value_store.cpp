//leetcode.com/problems/time-based-key-value-store/

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    
    string findValue(vector<pair<string, int>>& vec, int timestamp) {
        int low = 0;
        int high = vec.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].second == timestamp)
                return vec[mid].first;
            else if (vec[mid].second < timestamp)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high >= 0 ? vec[high].first : "";
    }
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";
        return findValue(mp[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */