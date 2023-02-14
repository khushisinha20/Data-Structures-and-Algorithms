//leetcode.com/problems/add-two-numbers-ii/

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
    void insertNodesToStack(ListNode* list, stack<int>& nodes) {
        while (list) {
            nodes.push(list -> val);
            list = list -> next;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1;
        stack<int> stack2;
        
        insertNodesToStack(l1, stack1);
        insertNodesToStack(l2, stack2);
        int carry = 0;
        int sum = 0;
        int firstListNode = 0;
        int secondListNode = 0;
        
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        
        while (!stack1.empty() || !stack2.empty() || carry) {
            sum = 0;
            
            if (!stack1.empty()) {
                firstListNode = stack1.top();
                stack1.pop();
            } else 
                firstListNode = 0;
            
            if (!stack2.empty()) {
                secondListNode = stack2.top();
                stack2.pop();
            } else
                secondListNode = 0;
            
            sum += (firstListNode + secondListNode + carry);
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            
            if (!dummy -> next) {
                current = node;
                dummy -> next = current;
            } else {
                node -> next = current;
                dummy -> next = node;
                current = node;
            }
        }
        
        return dummy -> next;
    }
};