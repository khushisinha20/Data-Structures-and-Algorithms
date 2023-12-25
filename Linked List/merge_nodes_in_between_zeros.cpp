//https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();  
        ListNode* current = dummy;
        
        ListNode* nodeInInitial = head;

        while (nodeInInitial != nullptr) {
            while (nodeInInitial && nodeInInitial -> val == 0) {
                nodeInInitial = nodeInInitial -> next;
            }

            int sum = 0;
            while (nodeInInitial && nodeInInitial -> val != 0) {
                sum += nodeInInitial -> val;
                ListNode* temp = nodeInInitial;
                nodeInInitial = nodeInInitial->next;
                delete temp;  
            }

            if (sum != 0) {
                current -> next = new ListNode(sum);
                current = current -> next;
            }
        }

        ListNode* result = dummy -> next;
        delete dummy;  
        return result;
    }
};
