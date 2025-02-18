

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> list[int]:
        if not root:
            return []
        
        # Only include the root if it's not a leaf
        boundary = [root.val] if not self.isLeaf(root) else []
        
        def leftBoundary(node):
            if node and not self.isLeaf(node):
                boundary.append(node.val)
                if node.left:
                    leftBoundary(node.left)
                else:
                    leftBoundary(node.right)

        def rightBoundary(node):
            if node and not self.isLeaf(node):
                if node.right:
                    rightBoundary(node.right)
                else:
                    rightBoundary(node.left)
                boundary.append(node.val)

        def leaves(node):
            if node:
                if self.isLeaf(node):
                    boundary.append(node.val)
                leaves(node.left)
                leaves(node.right)
        
        # Collect left boundary (excluding the root and leaves)
        if root.left:
            leftBoundary(root.left)
        
        # Collect leaves
        leaves(root.left)
        leaves(root.right)

        # Collect right boundary and reverse it
        if root.right:
            rightBoundaryNodes = []
            rightBoundary(root.right)
            boundary.extend(reversed(rightBoundaryNodes))
        
        return boundary
    
    def isLeaf(self, node):
        return node and not node.left and not node.right

# Test the Solution
root = TreeNode(1)
root.left = TreeNode(2, TreeNode(4), TreeNode(5, TreeNode(7), TreeNode(8)))
root.right = TreeNode(3, TreeNode(6, TreeNode(9), TreeNode(10)))

solution = Solution()
result = solution.boundaryOfBinaryTree(root)
print(result)  # Output should match the expected output [1,2,4,7,8,9,10,6,3]
