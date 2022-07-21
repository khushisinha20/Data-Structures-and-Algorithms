//leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = new ListNode();
        ListNode* curr = root;
        while (list1 && list2) {
            if (list1 -> val < list2 -> val) {
                curr -> next = list1;
                curr = curr -> next;
                list1 = list1 -> next;
            } else {
                curr -> next = list2;
                curr = curr -> next;
                list2 = list2 -> next;
            }
        }
        
        while (list1) {
            curr -> next = list1;
            curr = curr -> next;
            list1 = list1 -> next;
        }
        
        while (list2) {
            curr -> next = list2;
            curr = curr -> next;
            list2 = list2 -> next;
        }
        
        return root -> next;
    }
};