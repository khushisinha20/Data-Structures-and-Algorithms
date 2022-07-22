//leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        int sum = 0;
        while (l1 || l2 || carry) {
            sum = 0;
            if (l1) {
                sum += (l1 -> val);
                l1 = l1 -> next;
            }
            if (l2) {
                sum += (l2 -> val);
                l2 = l2 -> next;
            }
            
            sum += carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            curr -> next = node;
            curr = curr -> next;
        }
        return dummy -> next;
    }
};