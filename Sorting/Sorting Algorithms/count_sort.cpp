//Used when max element is similar to size of array 

//Time Complexity: O(n + k)

//Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int>& a) {
    auto i = max_element(a.begin(), a.end());
    return *i;
}

void createArrayOfCounts(vector<int>& a, vector<int>& count) {
    for (int i = 0; i < a.size(); ++i)
        ++count[a[i]];
}

void countSort(vector<int>& a) {
    int size = getMax(a) + 1;
    vector<int> count(size, 0);
    createArrayOfCounts(a, count);
    int i = 0;
    int j = 0;
    while (i < count.size()) {
        if (count[i]) {
            a[j++] = i;
            --count[i];
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
    countSort(a);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}