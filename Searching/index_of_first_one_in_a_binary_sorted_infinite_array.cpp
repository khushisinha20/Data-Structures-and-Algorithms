#include <bits/stdc++.h>
using namespace std;

int firstOccurenceOfOne(vector<int>& a, int start, int end) {
    int res = -1;
    while (start <= end) {
    int mid = start + (end - start) / 2;
        if (a[mid] == 1) {
            res = mid;
            if (mid > start)
                end = mid - 1;
        } else if (a[mid] < 1)
            start = mid + 1;
    }
    return res;
}

int searchInInfiniteSortedBinary(vector<int>& a) {
    int start = 0;
    int end = 1;
    while (a[end] != 1) {
        start = end;
        end *= 2;
    }
    return firstOccurenceOfOne(a, start, end);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << searchInInfiniteSortedBinary(a);
    return 0;
}