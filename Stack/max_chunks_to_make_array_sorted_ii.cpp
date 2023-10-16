#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stack;
        for (int num : arr) {
            int largest = num;
            while (!stack.empty() && stack.top() > num) {
                largest = max(largest, stack.top());
                stack.pop();
            }
            stack.push(largest);
        }
        return stack.size();
    }
};
