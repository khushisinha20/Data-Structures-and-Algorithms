//Time Complexity: O(n ^ 2)

//Stable

//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& a) {
    for (int i = 1; i < a.size(); ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    insertionSort(a);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    return 0;
}