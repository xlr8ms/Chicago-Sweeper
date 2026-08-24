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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else {
            //key == root->val
            //case1: 0 childern
            if(root->left == NULL && root->right == NULL){
                delete(root);
                return NULL;
            }
            //case2: 1 child
            if(root->left ==NULL || root->right == NULL){
                return root->left == NULL ? root->right : root->left;
            }
            //case3: 2 child
            TreeNode* Is = inorderS(root->right);
            root->val = Is->val;
            root->right = deleteNode(root->right, Is->val);
            return root;
        }
        return root;
    }
    TreeNode* inorderS(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
};