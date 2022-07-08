//Worst Case: O(n ^ 2)
//Average Case: O(n log n);

//Auxiliary Space: O(1)

//Unstable

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int left, int right) {
    int pivot = a[left];
    int i = left - 1; 
    int j = right + 1;
    while (true) {
        do {
            ++i;
        } while (a[i] < pivot);
        do {
            --j;
        } while (a[j] > pivot);
        if (i >= j)
            return j;
        swap(a[i], a[j]);    
    }
}

void quickSort(vector<int>& a, int left, int right) {
    if (left >= right)
        return;
    int p = partition(a, left, right);
    quickSort(a, left, p);
    quickSort(a, p + 1, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}