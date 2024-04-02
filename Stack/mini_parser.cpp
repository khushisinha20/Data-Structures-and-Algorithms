//leetcode.com/problems/mini-parser/

#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger()//leetcode.com/problems/mini-parser/ const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.length() == 1 and isdigit(s[0]))
            return s[0] - '0';

        if (s[0] != '[')
            return stoi(s);

        stack<NestedInteger> nestedStack;
        bool isNegative = false;
        bool isNumber = false;
        int num = 0;

        for (char c: s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                isNumber = true;
            } else if (c == '-') {
                isNegative = true;
            } else if (c == '[') {
                nestedStack.push(NestedInteger());
            } else {
                if (isNumber) {
                    num = isNegative ? num * -1 : num;
                    nestedStack.top().add(NestedInteger(num));
                    num = 0;
                    isNumber = false;
                    isNegative = false;
                }
                if (c == ']') {
                    NestedInteger nestedInteger = nestedStack.top();
                    nestedStack.pop();
                    if (nestedStack.empty())
                        return nestedInteger;
                    nestedStack.top().add(nestedInteger);
                }
            }
        }

        return NestedInteger();
    }
};
