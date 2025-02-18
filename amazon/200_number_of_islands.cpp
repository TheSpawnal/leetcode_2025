
// Given an m x n 2D binary grid grid which represents a 
// map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting 
// adjacent lands horizontally or vertically. You may assume all 
// four edges of the grid are all surrounded by water.

 

// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.


class Solution{
public: 
    void ExploreLand(vector<vector<char>>& grid, int r, int c){
        if(r>=grid.size() || r<0 || c>=grid[0].size() || c < 0){
            return;
        }
        if(grid[r][c] == '0'){
            return;
        }
        grid[r][c]='0';
        ExploreLand(grid,r+1,c);
        ExploreLand(grid,r-1,c);
        ExploreLand(grid,r,c+1);
        ExploreLand(grid,r,c-1);

    }
    int numIslands(vector<vector<char>>& grid){
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    ExploreLand(grid, i, j);
                    grid[i][j] == '0';
                }
            }
        }
        return cnt;
    }
};