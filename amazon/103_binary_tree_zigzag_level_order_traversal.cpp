
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
public:
    int levelsOfTree(TreeNode* root){
        if(root ==NULL) return 0;
        return 1 + max(levelsOfTree(root->left), levelsOfTree(root->right));
    }
    void NthLevelRev_display(TreeNode* root, int n, int level, vector<int>& v){
        if(root == NULL) return;
        if(n == level){
            v.push_back(root->val);
            return;
        }
        //right->left
        NthLevelRev_display(root->right,n+1, level, v);
        NthLevelRev_display(root->left, n+1,level,v);
    }
    void NthLevel_display(TreeNode* root, int n, int level, vector<int>& v){
        if(root==NULL) return;
        if(n==level){
            v.push_back(root->val);
            return;
        }
        //left->right
        NthLevel_display(root->left, n+1, level, v);
        NthLevel_display(root->right, n+1, level, v);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        int level = levelsOfTree(root);
        vector<vector<int>> ans;
        for(int i = 1; i <= level; i++){
            if(i%2 != 0){
                vector<int> v;
                NthLevel_display(root, 1, i, v);
                ans.push_back(v);
            }
            else{
                vector<int> v;
                NthLevelRev_display(root, 1, i, v);
                ans.push_back(v);
            }
        }
        return ans;
    }
};


//