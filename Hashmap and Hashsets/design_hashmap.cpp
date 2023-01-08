//leetcode.com/problems/design-hashmap/

#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    struct Node {
        Node* next;
        int key;
        int val;
        Node(int key, int val) {
            next = nullptr;
            this -> key = key;
            this -> val = val;
        }
    };
    
    Node* head = new Node(-1, -1);
    
    MyHashMap() {
    
    }
    
    void put(int key, int value) {
        Node* node = head;
        while (node -> next) {
            if (node -> key == key) {
                node -> val = value;
                return;
            }
            node = node -> next;
        }
        
        if (node -> key == key) {
            node -> val = value;
            return;
        }
        node -> next = new Node(key, value);
        return;
    }
    
    int get(int key) {
        Node* node = head;
        while (node) {
            if (node -> key == key)
                return node -> val;
            node = node -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        Node* first = head -> next;
        
        if (!first || get(key) == -1) 
            return;
        
        
        if (first -> key == key && !first -> next) {
            head -> next = first -> next;
            delete first;
            return;
        }
        
        if (first -> next -> key == key && !first -> next -> next) {
            Node* nextOfDeleted = first -> next -> next; 
            delete first -> next;
            first -> next = nextOfDeleted;
            return;
        }
        
        Node* node = head;
        
        while (node -> next) {
            if (node -> next -> key == key) {
                Node* temp = node -> next;
                node -> next = node -> next -> next;
                delete temp;
                return;
            }
            node = node -> next;
        } 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */