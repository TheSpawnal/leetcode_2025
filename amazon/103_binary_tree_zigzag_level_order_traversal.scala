// Given the root of a binary tree, return the zigzag level order 
// traversal of its nodes  values. 
// (i.e., from left to right, then right to left for the next 
// level and alternate between).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    def zigzagLevelOrder(root: TreeNode): List[List[Int]] = {
        if(root == null) return List.empty[List[Int]]

        def bfs(level: List[TreeNode], direction: Boolean): List[List[Int]]= {
            if(level.isEmpty) return Nil

            val nextLevel = level.flatMap(node=>List(Option(node.left),Option(node.right)).flatten)
            val values = if(direction)level.map(_.value)else level.map(_.value).reverse

            values :: bfs(nextLevel, !direction)
        }
        bfs(List(root), true)
    }
}
 