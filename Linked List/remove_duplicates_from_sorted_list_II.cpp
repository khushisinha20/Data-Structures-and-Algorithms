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
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr -> next != nullptr && curr -> val == curr -> next -> val) {
                while (curr -> next != nullptr && curr -> val == curr -> next -> val) {
                    ListNode* temp = curr;
                    curr = curr -> next;
                    delete temp;
                }
                prev -> next = curr -> next;
            } else {
                prev = prev -> next;
            }
            curr = curr -> next;
        }
        return dummy -> next;
    }
};