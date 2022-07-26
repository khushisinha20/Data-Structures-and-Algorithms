//leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr)
            return right;
        
        if (right == nullptr)
            return left;
        
        ListNode* curr = new ListNode();
        ListNode* merged_list = curr;
        
        while (left && right) {
            if (left -> val < right -> val) {
                curr -> next = left;
                curr = left;
                left = left -> next;
            } else {
                curr -> next = right;
                curr = right;
                right = right -> next;
            }
        }
        
        while (left) {
            curr -> next = left;
            curr = left;
            left = left -> next;
        }
        
        while (right) {
            curr -> next = right;
            curr = right;
            right = right -> next;
        }
        
        return merged_list -> next;
    }
    
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = nullptr;
        
        left = sortList(left);
        right = sortList(right);
        ListNode* result = merge(left, right);
        return result;
    }
};