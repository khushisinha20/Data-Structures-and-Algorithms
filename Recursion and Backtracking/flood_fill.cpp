//leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillColors(vector<vector<int>>& image, int sr, int sc, int color, int source_pixel_color) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        if (image[sr][sc] != source_pixel_color)
            return;
        if (image[sr][sc] == color)
            return;
        
        image[sr][sc] = color;
        
        fillColors(image, sr + 1, sc, color, source_pixel_color);
        fillColors(image, sr - 1, sc, color, source_pixel_color);
        fillColors(image, sr, sc + 1, color, source_pixel_color);
        fillColors(image, sr, sc - 1, color, source_pixel_color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int source_pixel_color = image[sr][sc];
        fillColors(image, sr, sc, color, source_pixel_color);
        return image;
    }
};