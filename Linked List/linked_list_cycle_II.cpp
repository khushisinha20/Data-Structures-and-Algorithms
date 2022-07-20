//leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        bool hasCycle = false;
        if (head == nullptr || head -> next == nullptr)
            return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }
        
        if (!hasCycle)
            return nullptr;
        
        slow = head;
        
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
    }
};