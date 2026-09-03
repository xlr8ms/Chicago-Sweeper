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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
           swapp(root);
           return root;
    }
    void swapp(TreeNode* root){
        if(root == NULL) return;
            TreeNode* curr = root;
            //if(curr->left != NULL && curr->right != NULL)
            swap(curr->left, curr->right);
            swapp(root->left);
            swapp(root->right);
    }
};