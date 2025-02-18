

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return[]

        result = []
        node_queue = deque([root])
        left_to_right = True

        while node queue:
            level_size = len(node_queue)
            current_level = []

            for _ in range(level_size):
                current_node = node_queue.popleft()
                current_level.append(current_node.val)

                if current_node.left:
                    node_queue.append(current_node.left)
                if current_node.right:
                    node_queue.append(current_node.right)

            if left_to_right:
                result.append(current_level[:])
            else:
                result.append(current_level[::-1])

            left_to_right = not left_to_right

        return result
