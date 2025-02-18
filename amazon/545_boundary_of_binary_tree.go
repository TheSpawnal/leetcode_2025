/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func boundaryOfBinaryTree(root *TreeNode) []int {
    var boundary []int
    if root == nil {
        return boundary
    }

    if !isLeaf(root) {
        boundary = append(boundary, root.Val)
    }

    // Collect left boundary excluding the root and leaves
    for cur := root.Left; cur != nil; cur = cur.Left {
        if !isLeaf(cur) {
            boundary = append(boundary, cur.Val)
        }
    }

    // Add leaves
    addLeaves(root, &boundary)

    // Collect right boundary and reverse it
    var rightBoundary []int
    for cur := root.Right; cur != nil; cur = cur.Right {
        if !isLeaf(cur) {
            rightBoundary = append(rightBoundary, cur.Val)
        }
    }

    // Since we need to reverse rightBoundary
    for i := len(rightBoundary) - 1; i >= 0; i-- {
        boundary = append(boundary, rightBoundary[i])
    }

    return boundary
}

func isLeaf(node *TreeNode) bool {
    return node.Left == nil && node.Right == nil
}

func addLeaves(node *TreeNode, boundary *[]int) {
    if node == nil {
        return
    }
    if isLeaf(node) {
        *boundary = append(*boundary, node.Val)
    }
    addLeaves(node.Left, boundary)
    addLeaves(node.Right, boundary)
}
