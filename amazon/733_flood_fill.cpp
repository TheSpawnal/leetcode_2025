#include <vector>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            my_dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
private:
    void my_dfs(vector<vector<int>>& image, int i, int j, int c0, int c1) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != c0) return;
        image[i][j] = c1;
        my_dfs(image, i + 1, j, c0, c1);
        my_dfs(image, i, j - 1, c0, c1);
        my_dfs(image, i, j + 1, c0, c1);
        my_dfs(image, i - 1, j, c0, c1);
    }
};