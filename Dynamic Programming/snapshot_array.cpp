//leetcode.com/problems/snapshot-array/

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    unordered_map<int, map<int, int>> snapshotRecord;
    int snapId = 0;

    SnapshotArray(int length) {

    }

    void set(int index, int val) {
        snapshotRecord[index][snapId] = val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto iterator = snapshotRecord[index].upper_bound(snap_id);
        if (iterator == snapshotRecord[index].begin())
            return 0;
        return prev(iterator) -> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
