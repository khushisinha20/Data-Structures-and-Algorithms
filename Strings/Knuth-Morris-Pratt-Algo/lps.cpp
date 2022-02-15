//www.youtube.com/watch?v=__Cu92rei1s&t=1506s

#include <bits/stdc++.h>
using namespace std;

vector<int> lpsArray(string s) {
    vector<int> lps(s.length(), 0);
    int i = 1;
    int len = 0;
    while (i < s.length()) {
        if (s[i] == s[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}

int main() {
    string s;
    cin >> s;
    vector<int> lps = lpsArray(s);
    for (int i = 0; i < lps.size(); ++i) {
        cout << lps[i] << " ";
    }
    return 0;
}