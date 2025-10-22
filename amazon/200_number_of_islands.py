# Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
# An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
# You may assume all four edges of the grid are all surrounded by water.

# Example 1:
# Input: grid = [
#   ["1","1","1","1","0"],
#   ["1","1","0","1","0"],
#   ["1","1","0","0","0"],
#   ["0","0","0","0","0"]
# ]
# Output: 1

# Example 2:
# Input: grid = [
#   ["1","1","0","0","0"],
#   ["1","1","0","0","0"],
#   ["0","0","1","0","0"],
#   ["0","0","0","1","1"]
# ]
# Output: 3

# Constraints:
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 300
# grid[i][j] is '0' or '1'.

#super memory friendly
class Solution:
    def numIslands(self, grid: List[List[str]])->int:
        if not grid:
            return 0
    def visit(i: int, j: int)-> None:
        if i < 0 or i >= len(grid) or j >= len(gird[0]) or grid[i][j] == '0'
            return
        grid[i][j] = '0'
        visit(i-1, j)
        visit(i+1, j)
        visit(i, j-1)
        visit(i, j+1)
    count = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j]=='1':
                count += 1
                visit(i,j)
    return count


#super runtime efficient
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        counter = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    grid[i][j] = "0"
                    counter += 1
                    bfs(i,j,grid)
        return counter

def bfs(i,j,grid):
    endi = len(grid)-1
    endj = len(grid[0])-1

    if i != endi:
        if grid[i+1][j] == "1":
            grid[i+1][j] = "0"
            bfs(i+1,j,grid)

    if i != 0:
        if grid[i-1][j] == "1":
            grid[i-1][j] = "0"
            bfs(i-1,j,grid)

    if j != endj:
        if grid[i][j+1] == "1":
            grid[i][j+1] = "0"
            bfs(i,j+1,grid)

    if j != 0:
        if grid[i][j-1] == "1":
            grid[i][j-1] = "0"
            bfs(i,j-1,grid)

    return
