object Solution {
    def floodFill(image: Array[Array[Int]], sr: Int, sc: Int, color: Int): Array[Array[Int]] = {
        val originalColor = image(sr)(sc)
        if (originalColor != color) {
            s_dfs(image, sr, sc, originalColor, color)
        }
        image
    }

    private def s_dfs(image: Array[Array[Int]], i: Int, j: Int, originalColor: Int, newColor: Int): Unit = {
        if (i < 0 || j < 0 || i >= image.length || j >= image(i).length || image(i)(j) != originalColor) {
            return
        }
        image(i)(j) = newColor
        s_dfs(image, i + 1, j, originalColor, newColor)
        s_dfs(image, i - 1, j, originalColor, newColor)
        s_dfs(image, i, j + 1, originalColor, newColor)
        s_dfs(image, i, j - 1, originalColor, newColor)
    }
}