#include <bits/stdc++.h>
using namespace std;

class disjointSet {
    vector<int> parent;
    vector<int> rank;
    public:
    disjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionOfNodes(int u, int v) {
        int parentOfU = find(u);
        int parentOfV = find(v);
        if (parentOfU == parentOfV)
            return;
        if (rank[parentOfU] < rank[parentOfV])
            parent[parentOfU] = parentOfV;
        else if (rank[parentOfV] < rank[parentOfU])
            parent[parentOfV] = parentOfU;
        else {
            parent[parentOfV] = parentOfU;
            ++rank[parentOfU];
        }
    }
};

int main() {
    disjointSet ds(7);
    ds.unionOfNodes(1, 2);
    ds.unionOfNodes(2, 3);
    ds.unionOfNodes(4, 5);
    ds.unionOfNodes(6, 7);
    ds.unionOfNodes(5, 6);
    if (ds.find(1) == ds.find(3))
        cout << "1 and 3 have same parent." << endl;
    else
        cout << "1 and 3 do not have same parent.";
    if (ds.find(1) == ds.find(6))
        cout << "1 and 6 have same parent." << endl;
    else
        cout << "1 and 6 do not have same parent.";
    return 0;
}