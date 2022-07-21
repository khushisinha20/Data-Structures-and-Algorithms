//leetcode.com/problems/spiral-matrix-iv/

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* curr = head;
        int rowStart = 0;
        int rowEnd = m - 1;
        int colStart = 0;
        int colEnd = n - 1;
        int list_value = curr -> val;
        int total_elements = 0;
        vector<vector<int>> matrix(m, vector<int> (n));
        
        while (total_elements != m * n) {
            for (int i = colStart; i <= colEnd && total_elements < m * n; ++i) {
                ++total_elements;
                matrix[rowStart][i] = list_value;
                if (curr -> next) {
                    list_value = curr -> next -> val;
                    curr = curr -> next;
                } else
                    list_value = -1;
            }
            ++rowStart;  
            
            for (int i = rowStart; i <= rowEnd && total_elements < m * n; ++i) {
                ++total_elements;
                matrix[i][colEnd] = list_value;
                if (curr -> next) {
                    list_value = curr -> next -> val;
                    curr = curr -> next;
                } else
                    list_value = -1;
            }
            --colEnd;
            
            for (int i = colEnd; i >= colStart && total_elements < m * n; --i) {
                ++total_elements;
                matrix[rowEnd][i] = list_value;
                if (curr -> next) {
                    list_value = curr -> next -> val;
                    curr = curr -> next;
                } else
                    list_value = -1;
            }
            --rowEnd;
            
            for (int i = rowEnd; i >= rowStart && total_elements < m * n; --i) {
                ++total_elements;
                matrix[i][colStart] = list_value;
                if (curr -> next) {
                    list_value = curr -> next -> val;
                    curr = curr -> next;
                } else
                    list_value = -1;
            }
            ++colStart;
        }
        
        return matrix;
    }
};