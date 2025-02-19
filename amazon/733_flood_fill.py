class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        init_color = image[sr][sc]
        rows, cols = len(image), len(image[0])

        def backtracking(i, j, grid):
            if i<0 or i >= rows or j<0 or j>=cols: #base case
                return
            if init_color != grid[i][j] or grid[i][j] == color:
                return
            grid[i][j] = color

            backtracking(i-1, j, grid)
            backtracking(i, j-1, grid)
            backtracking(i+1, j, grid)
            backtracking(i, j+1, grid)

        backtracking(sr, sc, image)
        return image

#alternative faster
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image
        self.changeColor(image, sr, sc, color, image[sr][sc])
        return image

    def changeColor(self, image, sr, sc, color, oldColor):
        if sr < 0 or sc < 0 or sr >= len(image) or sc >= len(image[sr]) or image[sr][sc] != oldColor:
            return
        image[sr][sc] = color
        self.changeColor(image, sr+1, sc, color, oldColor)
        self.changeColor(image, sr-1, sc, color, oldColor)
        self.changeColor(image, sr, sc+1, color, oldColor)
        self.changeColor(image, sr, sc-1, color, oldColor)