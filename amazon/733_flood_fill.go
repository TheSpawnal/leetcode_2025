func floodFill(image [][]int, sr int, sc int, color int) [][]int {
    originalColor := image[sr][sc]
    if originalColor == color {
        return image
    }
    my_dfs(image, sr, sc, originalColor, color)
    return image
}

func my_dfs(image [][]int, i int, j int, originalColor int, newColor int) {
    if i < 0 || j < 0 || i >= len(image) || j >= len(image[0]) || image[i][j] != originalColor {
        return
    }
    image[i][j] = newColor
    my_dfs(image, i+1, j, originalColor, newColor)
    my_dfs(image, i-1, j, originalColor, newColor)
    my_dfs(image, i, j+1, originalColor, newColor)
    my_dfs(image, i, j-1, originalColor, newColor)
}
