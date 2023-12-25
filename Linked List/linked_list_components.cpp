//https://leetcode.com/problems/linked-list-components/

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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* current = head;
        int components = 0;
        bool inComponent = false;
        
        while (current != nullptr) {
            if (numSet.count(current -> val))
                inComponent = true;
            else {
                if (inComponent) {
                    ++components;
                    inComponent = false;
                }
            }
            
            current = current -> next;
        }
        
        if (inComponent)
            ++components;
        
        return components;
    }
};