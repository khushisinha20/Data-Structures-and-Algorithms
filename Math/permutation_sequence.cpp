//leetcode.com/problems/permutation-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n + 1, 1);
        string result = "";
        
        int sum = 1;
        for (int i = 1; i <= n; ++i) {
            sum *= i;
            factorial[i] = sum;
        }
        
        for (int i = 1; i <= n; ++i)
            numbers.push_back(i);
        
        --k;
        
        for (int i = 1; i <= n; ++i) {
            int index = k / factorial[n - i];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k -= index * factorial[n - i];
        }
        
        return result;
    }
};