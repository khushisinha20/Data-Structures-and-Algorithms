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
    int getLength(ListNode* head) {
        ListNode* current = head;
        int length = 0;
        
        while (current) {
            ++length;
            current = current -> next;
        }
        
        return length;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = getLength(head);
        vector<ListNode*> result(k, nullptr);
        
        int nodesPerPart = length / k;
        int extraNodes = length % k;
        int position = 0;
        ListNode* currentNode = head;
        
        while (currentNode) {
            int nodesInCurrentPart = nodesPerPart + (extraNodes > 0 ? 1 : 0);
            if (extraNodes > 0)
                --extraNodes;
            
            ListNode* partStart = currentNode;
            ListNode* partEnd = currentNode;
            
            for (int nodeIndex = 0; nodeIndex < nodesInCurrentPart - 1 and partEnd; ++nodeIndex) {
                partEnd = partEnd -> next;
            }
            
            if (partEnd) {
                currentNode = partEnd -> next;
                partEnd -> next = nullptr;
                result[position++] = partStart;
            }
        }
        
        return result;
    }
};