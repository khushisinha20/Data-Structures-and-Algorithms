//leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class ListNode {
        public:
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int key, int val) {
            this -> key = key;
            this -> val = val;
        }
    };
    
    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);
    int cache_capacity;
    unordered_map<int, ListNode*> mp;
    
    LRUCache(int capacity) {
        head -> next = tail;
        tail -> prev = head;
        cache_capacity = capacity;
    }
    
    void addToList(ListNode* node) {
        ListNode* temp = head -> next; 
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
    }
    
    void removeFromList(ListNode* node) {
        ListNode* previous_node = node -> prev;
        ListNode* next_node = node -> next;
        previous_node -> next = next_node;
        next_node -> prev = previous_node;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            removeFromList(mp[key]);
            addToList(mp[key]);
            return mp[key] -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            removeFromList(mp[key]);
            mp.erase(key);
        }
        if (mp.size() == cache_capacity) {
            mp.erase(tail -> prev -> key);
            removeFromList(tail -> prev);
        }   
        
        ListNode* node = new ListNode(key, value);
        addToList(node);
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */