//leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            res *= 2;
            res += curr -> val;
            curr = curr -> next;
        }
        
        return res;
    }
};