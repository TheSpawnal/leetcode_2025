/*
You are given an image represented by an m x n grid of integers image, 
where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. 
Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

-Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent 
(pixels that share a side with the original pixel, either horizontally or vertically) 
and shares the same color as the starting pixel.
-Keep repeating this process by checking neighboring pixels of the updated pixels and
modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:
The starting pixel is already colored with 0, which is the same as the target color. 
Therefore, no changes are made to the image.


Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
all pixels connected by a path of the same color as the starting pixel (i.e., 
the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or 
vertically connected to the starting pixel.

Constraints:
m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void my_dfs(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int originalColor){
    if(sr<0||sr>=imageSize||sc<0||sc>=(imageColSize[sr])|| image[sr][sc] != originalColor){
        return;
    }
    image[sr][sc] = newColor;
    my_dfs(image, imageSize, imageColSize, sr+1, sc, newColor, originalColor);
    my_dfs(image, imageSize, imageColSize, sr, sc+1, newColor, originalColor);
    my_dfs(image, imageSize, imageColSize, sr-1, sc, newColor, originalColor);
    my_dfs(image, imageSize, imageColSize, sr, sc-1, newColor, originalColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*)*imageSize);
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    int pixel = image[sr][sc];
    if(pixel != color){
        my_dfs(image, imageSize, imageColSize, sr, sc , color, pixel);
    }
    return image;
}