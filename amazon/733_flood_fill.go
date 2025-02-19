func floodFill(image [][]int, sr int, sc int, color int) [][]int {
    originalColor := image[sr][sc]
    if originalColor == color {
        return image
    }
    dfs(image, sr, sc, originalColor, color)
    return image
}

func dfs(image [][]int, i int, j int, originalColor int, newColor int) {
    if i < 0 || j < 0 || i >= len(image) || j >= len(image[0]) || image[i][j] != originalColor {
        return
    }
    image[i][j] = newColor
    dfs(image, i+1, j, originalColor, newColor)
    dfs(image, i-1, j, originalColor, newColor)
    dfs(image, i, j+1, originalColor, newColor)
    dfs(image, i, j-1, originalColor, newColor)
}
