//leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*> sumNodeMapping;
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* currentNode = head;
        sumNodeMapping[0] = dummy;
        
        while (currentNode) {
            prefixSum += currentNode -> val;
            if (sumNodeMapping.find(prefixSum) != sumNodeMapping.end()) {
                ListNode* previousOccurence = sumNodeMapping[prefixSum];
                ListNode* zeroSubarrayCurrentNode = previousOccurence;
                int prefixSumTillNow = prefixSum;
                
                while (zeroSubarrayCurrentNode != currentNode) {
                    zeroSubarrayCurrentNode = zeroSubarrayCurrentNode -> next;
                    prefixSumTillNow += zeroSubarrayCurrentNode -> val;
                    if (zeroSubarrayCurrentNode != currentNode)
                        sumNodeMapping.erase(prefixSumTillNow);
                }
                previousOccurence -> next = zeroSubarrayCurrentNode -> next;
            } else 
                sumNodeMapping[prefixSum] = currentNode;
            currentNode = currentNode -> next;
        }
        
        return dummy -> next;
    }
};