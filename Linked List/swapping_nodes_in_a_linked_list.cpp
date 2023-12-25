//leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < k; ++i) {
            if (fast == nullptr) {
                return nullptr; 
            }
            fast = fast -> next;
        }

        while (fast != nullptr) {
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }

    ListNode* getKthFromStart(ListNode* head, int k) {
        ListNode* current = head;
        int position = 0;

        while (current != nullptr && position != k) {
            current = current -> next;
            ++position;
        }

        return current;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstNodeFromStart = getKthFromStart(head, k - 1);
        ListNode* secondNodeFromEnd = getKthFromEnd(head, k);

        if (firstNodeFromStart == nullptr || secondNodeFromEnd == nullptr || firstNodeFromStart == secondNodeFromEnd) {
            return head; 
        }

        int tempValue = firstNodeFromStart -> val;
        firstNodeFromStart -> val = secondNodeFromEnd -> val;
        secondNodeFromEnd -> val = tempValue;

        return head;
    }
};
