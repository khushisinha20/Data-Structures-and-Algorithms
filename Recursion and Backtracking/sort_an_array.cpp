#include <bits/stdc++.h>
using namespace std;

void insertIntoSortedPos(vector<int>& arr, int temp) {
    if (arr.size() == 0 || arr[arr.size() - 1] <= temp) {
        arr.push_back(temp);
        return;
    }
    int val = arr[arr.size() - 1];
    arr.pop_back();
    insertIntoSortedPos(arr, temp);
    arr.push_back(val);
}

void sortArray(vector<int>& arr) {
    if (arr.size() == 1)
        return;
    int temp = arr[arr.size() - 1];
    arr.pop_back();
    sortArray(arr);
    insertIntoSortedPos(arr, temp);
}

int main() {
    vector<int> arr = {3, 2, 0, 9, 7, 1 ,4};
    sortArray(arr);
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    return 0;
}