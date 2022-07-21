//leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* list) {
        ListNode* prev = nullptr;
        ListNode* curr = list;
        ListNode* next = nullptr; 
        while (curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head -> next == nullptr)
            return true;
        ListNode* curr = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        slow -> next = reverse(slow -> next);
        
        slow = slow -> next;
        
        while (curr && slow) {
            if (curr -> val != slow -> val)
                return false;
            
            curr = curr -> next;
            slow = slow -> next;
        }
        
        return true;
    }
};