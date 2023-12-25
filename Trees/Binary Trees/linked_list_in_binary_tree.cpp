//leetcode.com/problems/linked-list-in-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubPathFromCurrentNode(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        
        if (!root)
            return false;
        
        if (head -> val == root -> val)
            return isSubPathFromCurrentNode(head -> next, root -> left) or isSubPathFromCurrentNode(head -> next, root -> right);
        else
            return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        
        if (!root)
            return false;
        
        return isSubPathFromCurrentNode(head, root) or
               isSubPath(head, root -> left) or
               isSubPath(head, root -> right);
    }
};