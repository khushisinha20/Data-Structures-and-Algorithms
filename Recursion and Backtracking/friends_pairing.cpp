#include <bits/stdc++.h>
using namespace std;

int counter = 1;

void solution(int i, int n, string ans_so_far, vector<bool> used) {
    if (i > n) {
        cout << counter << "." << ans_so_far;
        cout << '\n';
        ++counter;
        return;
    }
    
    if (used[i])
        solution(i + 1, n, ans_so_far, used);
    else {
        used[i] = true;
        solution(i + 1, n, ans_so_far + "(" + to_string(i) + ") ", used);
        for (int j = i + 1; j <= n; ++j) {
            if (!used[j]) {
                used[j] = true;
                solution(i + 1, n, ans_so_far + "(" + to_string(i) + "," + to_string(j) + ") ", used);
                used[j] = false;
            }
        }
        used[i] = false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool> used(n + 1, false);
    solution(1, n, "", used);
}