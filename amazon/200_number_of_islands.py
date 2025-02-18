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