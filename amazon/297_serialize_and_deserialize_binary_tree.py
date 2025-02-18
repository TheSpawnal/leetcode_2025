from collections import deque

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        
        queue = deque([root])
        result = []
        
        while queue:
            node = queue.popleft()
            if node:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append("null")
        
        return ' '.join(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        
        values = data.split()
        root = TreeNode(int(values[0]))
        queue = deque([root])
        index = 1
        
        while queue:
            node = queue.popleft()
            if values[index] != "null":
                node.left = TreeNode(int(values[index]))
                queue.append(node.left)
            index += 1
            
            if values[index] != "null":
                node.right = TreeNode(int(values[index]))
                queue.append(node.right)
            index += 1
        
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
