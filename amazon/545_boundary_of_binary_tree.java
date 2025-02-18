import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    // Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> boundary = new ArrayList<>();
        if (root == null) return boundary;

        if (!isLeaf(root)) {
            boundary.add(root.val);
        }

        TreeNode cur = root.left;
        while (cur != null) {
            if (!isLeaf(cur)) boundary.add(cur.val);
            cur = (cur.left != null) ? cur.left : cur.right;
        }

        addLeaves(root, boundary);
        List<Integer> rightBoundary = new ArrayList<>();
        cur = root.right;
        while (cur != null) {
            if (!isLeaf(cur)) rightBoundary.add(cur.val);
            cur = (cur.right != null) ? cur.right : cur.left;
        }
        Collections.reverse(rightBoundary);
        boundary.addAll(rightBoundary);

        return boundary;
    }

    private void addLeaves(TreeNode node, List<Integer> boundary) {
        if (node == null) return;
        if (isLeaf(node)) {
            boundary.add(node.val);
        } else {
            addLeaves(node.left, boundary);
            addLeaves(node.right, boundary);
        }
    }

    private boolean isLeaf(TreeNode node) {
        return (node.left == null && node.right == null);
    }

    public static void main(String[] args) {
        // Example tree setup
        TreeNode root = new TreeNode(1, 
            new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(7), new TreeNode(8))), 
            new TreeNode(3, new TreeNode(6, new TreeNode(9), new TreeNode(10)), null));
        
        Solution sol = new Solution();
        List<Integer> result = sol.boundaryOfBinaryTree(root);
        System.out.println(result); // Expected: [1, 2, 4, 7, 8, 9, 10, 6, 3]
    }
}
