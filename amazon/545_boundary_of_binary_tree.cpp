// 545. Boundary of Binary Tree
// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates.)

// Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

// The right-most node is also defined by the same way with left and right exchanged.

// Example 1

// Input:
//   1
//    \
//     2
//    / \
//   3   4

// Ouput:
// [1, 3, 4, 2]

// Explanation:
// The root doesn't have left subtree, so the root itself is left boundary.
// The leaves are node 3 and 4.
// The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
// So order them in anti-clockwise without duplicates and we have [1,3,4,2].


// Example 2

// Input:
//     ____1_____
//    /          \
//   2            3
//  / \          /
// 4   5        6
//    / \      / \
//   7   8    9  10

// Ouput:
// [1,2,4,7,8,9,10,6,3]

// Explanation:
// The left boundary are node 1,2,4. (4 is the left-most node according to definition)
// The leaves are node 4,7,8,9,10.
// The right boundary are node 1,3,6,10. (10 is the right-most node).
// So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].


//Definition for a binary tree node.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    vector<int> boundaryOfBinaryTree(TreeNode *root){
        if(!root) return{};
        vector<int> leftBound, leaves, rightBound;
        unordered_set<int> visited;

        if(!isLeaf(root)) leftBound.push_back(root->val);
        visited.insert(root->val);
        getBoundary(root->left, leftBound, visited,true, false); //get left boundary
        getLeaves(root, leaves, visited);
        getBoundary(root->right, rightBound, visited, false, true);
        leftBound.insert(leftBound.end(), leaves.begin(), leaves.end());
        for(auto it = rightBound.rbegin(); it != rightBound.rend(); it++){
            if(visited.insert(*it).second){
                leftBound.push_back(*it);
            }
        }
        return leftBound;
    }
private:
    bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
    void getBoundary(TreeNode* node, vector<int>& res, unordered_set<int>& visited, bool isLeft, bool isRight){
        if(!node) return;
        if(isLeft && visited.insert(node->val).second) res.push_back(node->val);
        if(!isLeft && !isRight && isLeaf(node) && visited.insert(node->val).second) res.push_back(node->val);
        getBoundary(node->left, res, visited, isLeft, isRight && !node->val);
        getBoundary(node->right, res, visited, isLeft && !node->left ,isRight);

        if(isRight && visited.insert(node->val).second) res.push_back(node->val);
    }

    void getLeaves(TreeNode* node, vector<int>& res, unordered_set<int>& visited){
        if(!node) return;
        if(isLeaf(node) & visited.insert(node->val).second){
            res.push_back(node->val);
            return;
        }
        getLeaves(node->left, res, visited);
        getLeaves(node->right, res, visited);
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> boundary = sol.boundaryOfBinaryTree(root);
    cout << "Boundary of the binary tree: ";
    for(int num: boundary){
        cout << num << " ";
    }
    cout << endl;

    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}