
# Given the root of a binary tree, return the length of the diameter of the tree.
# The diameter of a binary tree is the length of the longest path between any two 
# nodes in a tree. This path may or may not pass through the root.
# The length of a path between two nodes is represented by the number of edges between them.

# Example 1:
# Input: root = [1,2,3,4,5]
# Output: 3
# Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
# Example 2:
# Input: root = [1,2]
# Output: 1
 
# Constraints:
# -The number of nodes in the tree is in the range [1, 10^4].
# {-100 <= Node.val <= 100}

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def diameter(node, res):
            if not node:
                return 0
            
            #recursively calculate the diameter of left and right subtrees
            left = diameter(node.left, res)
            right = diameter(node.right, res)
            #update max diameter encoutered 
            res[0] = max(res[0], left + right)
            return max(left, right)+1
        res =[0]
        diameter(root, res)
        return res[0]
    
#alternative: 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def getMaxLengthOfSubTree(root):
            queue = deque([root])
            maxLength = 0
            while(queue):
                for i in range(len(queue)):
                    node = queue.popleft()
                    if node:
                        if node.left:
                            queue.append(node.left)
                        if node.right:
                            queue.append(node.right)
                maxLength += 1
            return maxLength


        actualMax = 0
        queue = deque([root])
        while(queue):
            node = queue.popleft()
            if node:
                queue.append(node.left)
                queue.append(node.right)
                if node.right:
                    maxLengthOfRightSubTree = getMaxLengthOfSubTree(node.right)
                else:
                    maxLengthOfRightSubTree = 0
                if node.left:
                    maxLengthOfLeftSubTree = getMaxLengthOfSubTree(node.left)
                else:
                    maxLengthOfLeftSubTree = 0
                actualMax = max(actualMax, maxLengthOfRightSubTree + maxLengthOfLeftSubTree)
        return actualMax
