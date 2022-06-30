//Works by repeatedly finding minimum element from the unsorted part and putting it at the beginning 

//Time Complexity O(n)

//Space Complexity O(1)

//Unstable

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) 
                min_idx = j;
        }
        swap(a[i], a[min_idx]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    selectionSort(a);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}