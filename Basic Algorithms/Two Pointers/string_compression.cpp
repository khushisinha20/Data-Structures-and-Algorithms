#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1)
            return 1;
        int start = 0;
        int index = 0;
        while (start < chars.size()) {
            int end = start + 1;
            while (end < chars.size() && chars[start] == chars[end]) {
                end++;
            }
            chars[index++] = chars[start];
            if (end - start > 1) {
                string group_size = to_string(end - start);
                for (int i = 0; i < group_size.length(); ++i) {
                    chars[index++] = group_size[i];
                }
            }
            start = end;
        }
        return index;
    }
};