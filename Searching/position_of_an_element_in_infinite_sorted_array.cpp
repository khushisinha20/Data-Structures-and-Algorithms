#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& a, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int searchInInfiniteSorted(vector<int>& a, int target) {
    int start = 0;
    int end = 1;
    while (a[end] < target) {
        start = end;
        end *= 2;
    }
    return binarySearch(a, start, end, target);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int target;
    cin >> target;
    cout << searchInInfiniteSorted(a, target);
    return 0;
}