//leetcode.com/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class comparator {
    public:
    bool operator() (const ListNode* a, const ListNode* b) {
        return a -> val > b -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        
        priority_queue<ListNode*, vector<ListNode*>, comparator> min_heap;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                min_heap.push(lists[i]);
        
        while (!min_heap.empty()) {
            auto least = min_heap.top();
            min_heap.pop();
            curr -> next = least;
            curr = least;
            if (least -> next)
                min_heap.push(least -> next);
        }
        
        return dummy -> next;
    }
};