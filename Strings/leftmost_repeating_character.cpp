#include <bits/stdc++.h>
using  namespace std;

int firstRepeatingCharacter(string s) {
    int  idx = -1;
    vector<bool> visited(256, false);
    for (int i = s.length(); i >= 0; --i) {
        if (visited[s[i]]) {
            idx = i;
        } else {
            visited[s[i]] = true;
        }
    }
    return idx;
}

int main() {
    string s;
    cin >> s;
    cout << firstRepeatingCharacter(s);
    return 0;
}