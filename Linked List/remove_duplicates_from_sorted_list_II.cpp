//leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head -> next)
            return head;
        
        ListNode* dummy = new ListNode(-1, head);
        ListNode* previous_unique = dummy;
        ListNode* current = head;
        
        while (current) {
            bool isDuplicate = false;
            while (current -> next and current -> val == current -> next -> val) {
                isDuplicate = true;
                current = current -> next;
            }
            
            if (isDuplicate) 
                previous_unique -> next = current -> next;
            else
                previous_unique = previous_unique -> next;
            
            current = current -> next;
        }
        
        return dummy -> next;
    }
};