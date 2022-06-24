//practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

#include<bits/stdc++.h>
using namespace std;

vector<string> res;
void generatePaths(vector<vector<int>> &m, vector<vector<bool>> visited, int sr, int sc, int n, string s) {
    if (sr < 0 || sr >= n || sc < 0 || sc >= n || visited[sr][sc] || m[sr][sc] == 0)
        return;
            
    if (sr == n - 1 && sc == n - 1) {
        res.push_back(s);
        return;
    }
        
    visited[sr][sc] = true;
    generatePaths(m, visited, sr - 1, sc, n, s + "U");
    generatePaths(m, visited, sr + 1, sc, n, s + "D");
    generatePaths(m, visited, sr, sc - 1, n, s + "L");
    generatePaths(m, visited, sr, sc + 1, n, s + "R");
    visited[sr][sc] = false;
}
    
vector<string> findPath(vector<vector<int>> &m, int n) {
    string path = "";
    vector<vector<bool>> visited(n, vector<bool> (n));
    generatePaths(m, visited, 0, 0, n, path);
    return res;
}