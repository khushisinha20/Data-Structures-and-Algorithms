//leetcode.com/problems/operations-on-tree/

#include <bits/stdc++.h>
using namespace std;

class LockingTree {
public:
    vector<vector<int>> tree;
    vector<int> status;
    vector<int> parent;

    vector<vector<int>> makeTree(vector<int>& parent) {
        int n = parent.size();
        tree.resize(n);
        for (int i = 1; i < n; ++i)
            tree[parent[i]].push_back(i);
        return tree;
    }

    LockingTree(vector<int>& parent) {
        vector<vector<int>> tree = makeTree(parent);
        int n = parent.size();
        status.resize(n);
        for (int i = 0; i < n; ++i)
            status[i] = -1;
        this -> parent = parent;
    }

    bool isLocked(int num) {
        return status[num] != -1;
    }

    bool lock(int num, int user) {
        if (!isLocked(num)) {
            status[num] = user;
            return true;
        }

        return false;
    }

    bool unlock(int num, int user) {
        if (status[num] == user) {
            status[num] = -1;
            return true;
        }

        return false;
    }

    bool hasLockedDescendents(int num) {
        if (isLocked(num))
            return true;

        for (int child: tree[num]) {
            if (hasLockedDescendents(child))
                return true;
        }

        return false;
    }

    bool hasLockedAncestors(int num) {
        while (num != -1) {
            if (isLocked(num))
                return true;
            num = parent[num];
        }

        return false;
    }

    void unlockDescendents(int num) {
        for (int child: tree[num]) {
            if (isLocked(child))
                status[child] = -1;
            unlockDescendents(child);
        }
    }

    bool upgrade(int num, int user) {
        if (isLocked(num) or !hasLockedDescendents(num) or hasLockedAncestors(num))
            return false;

        if (!lock(num, user))
            return false;

        unlockDescendents(num);
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
