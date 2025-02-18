// Serialization is the process of converting a data structure or object
// into a sequence of bits so that it can be stored in a file or memory buffer, 
// or transmitted across a network connection link to be reconstructed later in 
// the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. 
// There is no restriction on how your serialization/deserialization algorithm should work. 
// You just need to ensure that a binary tree can be serialized to a string and this 
// string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. 
// You do not necessarily need to follow this format, so please be creative and 
// come up with different approaches yourself.

// example1: 
// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string output;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();

            if (node == nullptr) {
                output += "null ";
                continue;
            }

            // Append the node value followed by a space to separate numbers
            output += to_string(node->val) + " ";

            // Always enqueue children nodes or nullptr for clear parsing
            queue.push(node->left);
            queue.push(node->right);
        }
        return output;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        getline(ss, item, ' ');
        if (item == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();

            // Process left child
            if (!getline(ss, item, ' ')) break;
            if (item != "null") {
                node->left = new TreeNode(stoi(item));
                queue.push(node->left);
            }

            // Process right child
            if (!getline(ss, item, ' ')) break;
            if (item != "null") {
                node->right = new TreeNode(stoi(item));
                queue.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));