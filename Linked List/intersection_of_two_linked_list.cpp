//leetcode.com/problems/intersection-of-two-linked-lists/

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
    int findListLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            ++length;
            head = head -> next;
        }
        return length;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = findListLength(headA);
        int lengthB = findListLength(headB);
        ListNode* currA = headA;
        ListNode* currB = headB;
        if (lengthA >= lengthB) {
            int length = 0;
            for (ListNode* curr = headA; length <= lengthA - lengthB; curr = curr -> next) {
                currA = curr;
                ++length;
            }
        } else {
            int length = 0;
            for (ListNode* curr = headB; length <= lengthB - lengthA; curr = curr -> next) {
                currB = curr;
                ++length;
            }
        }
        
        while (currA != nullptr && currB != nullptr) {
            if (currA == currB)
                return currA;
            currA = currA -> next;
            currB = currB -> next;
        }
        return nullptr;
    }
};