//Time Complexity: O(n ^ 2)

//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void cycleSort(vector<int>& a) {
    int i = 0;
    while (i < a.size()) {
        int correct_index = a[i] - 1;
        if (a[i] != a[correct_index]) {
            swap(a[i], a[correct_index]);
        } else {
            ++i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cycleSort(a);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}