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
    int cnt = 1, ans;
    int kthSmallest(TreeNode* root, int k) {
        in(root, k);
        return ans;
    } 
    void in(TreeNode* root, int k){
        if(root == NULL) return;

        in(root->left, k);
        if(cnt==k) ans = root->val;
        cnt++;
        in(root->right, k);
    }
};