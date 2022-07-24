//leetcode.com/problems/next-greater-node-in-linked-list/

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> node_values;
        ListNode* curr = head;
        while (curr) {
            node_values.push_back(curr -> val);
            curr = curr -> next;
        }
        
        stack<int> s;
        vector<int> res(node_values.size(), 0);
        for (int i = node_values.size() - 1; i >= 0; --i) {
            if (s.empty())
                res[i] = 0;
            else if (!s.empty() && s.top() > node_values[i])
                res[i] = s.top();
            else if (!s.empty() && s.top() <= node_values[i]) {
                while (!s.empty() && s.top() <= node_values[i])
                    s.pop();
                if (s.empty())
                    res[i] = 0;
                else if (s.top() > node_values[i])
                    res[i] = s.top();
            }
            s.push(node_values[i]);
        } 
        return res;
    }
};