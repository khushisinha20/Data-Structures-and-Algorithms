//Works by repeatedly swapping the adjacent elements if they are in the wrong order

//Time Complexity O(n ^ 2)

//Space Complexity O(1)

//Stable

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;    
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    bubbleSort(a);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}