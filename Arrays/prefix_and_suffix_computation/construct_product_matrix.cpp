//leetcode.com/problems/construct-product-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 12345;
    
    vector<int> getLeftProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n);
        leftProduct[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            leftProduct[i] = ((leftProduct[i - 1] % MOD) * (nums[i] % MOD)) % MOD;
        
        return leftProduct;
    }
    
    vector<int> getRightProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightProduct(n);
        rightProduct[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i)
            rightProduct[i] = ((rightProduct[i + 1] % MOD) * (nums[i] % MOD)) % MOD;
        
        return rightProduct;
    }
    
    vector<int> getFlattenedMatrix(vector<vector<int>>& grid) {
        vector<int> flattened;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                flattened.push_back(grid[i][j]);
        
        return flattened;
    }
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int> flattenedMatrix = getFlattenedMatrix(grid);
        vector<int> leftProduct = getLeftProduct(flattenedMatrix);
        vector<int> rightProduct = getRightProduct(flattenedMatrix);
        
        int n = grid.size();
        int m = grid[0].size();
        
        int k = 0;
        vector<vector<int>> productMatrix(n, vector<int> (m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int left = k - 1 >= 0 ? leftProduct[k - 1] : 1;
                int right = k + 1 < flattenedMatrix.size() ? rightProduct[k + 1] : 1;
                productMatrix[i][j] = ((left % MOD) * (right % MOD)) % MOD;
                ++k;
            }
        }
        
        return productMatrix;
    }
};