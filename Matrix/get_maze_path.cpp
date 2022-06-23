#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    vector<string> res;
    
    if (sr == dr && sc == dc)
        return {""};
    
    vector<string> horizontal_paths;
    vector<string> vertical_paths;
    if (sc < dc) 
        horizontal_paths = getMazePaths(sr, sc + 1, dr, dc);
        
    if (sr < dr)
        vertical_paths = getMazePaths(sr + 1, sc, dr, dc);
        
    for (auto path: horizontal_paths)
        res.push_back("h" + path);
        
    for (auto path: vertical_paths)
        res.push_back("v" + path);
        
    return res;
}