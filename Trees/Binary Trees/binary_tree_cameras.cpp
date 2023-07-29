//leetcode.com/problems/binary-tree-cameras/

#include <bits/stdc++.h>
using namespace std;

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
    int noCamera = 0;
    int noCameraButMonitored = 1;
    int hasCamera = 2;
    
    int dfs(TreeNode* node, int& minCameras) {
        if (!node)
            return noCameraButMonitored;
        
        int left = dfs(node -> left, minCameras);
        int right = dfs(node -> right, minCameras);
        
        if (left == noCamera or right == noCamera) {
            ++minCameras;
            return hasCamera;
        }
        
        if (left == hasCamera or right == hasCamera)
            return noCameraButMonitored;
        
        if (left == noCameraButMonitored or right == noCameraButMonitored)
            return noCamera;
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        int minCameras = 0;
        if (dfs(root, minCameras) == noCamera)
            ++minCameras;
        return minCameras;
    }
};