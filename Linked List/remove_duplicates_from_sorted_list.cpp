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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current) {
            ListNode* nextDistinct = current -> next;
            while (nextDistinct and current -> val == nextDistinct -> val) {
                ListNode* temp = nextDistinct;
                nextDistinct = nextDistinct -> next;
                delete temp;
            }
            current -> next = nextDistinct;
            current = nextDistinct;
        }
        return head;
    }
};