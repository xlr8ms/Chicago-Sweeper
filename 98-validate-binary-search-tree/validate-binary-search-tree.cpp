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
    bool valid(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL) return 1;

        if(min!= NULL && root->val <= min->val) return 0;
        if(max!=NULL && root->val >= max->val) return 0;

        return valid(root->left, min, root) && valid(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }
};