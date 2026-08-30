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
    vector<int> v;
    void recoverTree(TreeNode* root) {
        in(root);
        vector<int> ans = v;
        sort(v.begin(), v.end());
        int v1, v2, i1, i2;
        for(int i=0; i<v.size(); i++){
            if(ans[i] != v[i]){
                v1 = ans[i];
                i1 = i;
                break;
            }
        }
        for(int i=i1+1; i<v.size(); i++){
            if(ans[i] != v[i]){
                v2 = ans[i];
                break;
            }
        }
        TreeNode* curr1 = search(root, v1);
        TreeNode* curr2 = search(root, v2);
        swap(curr1->val, curr2->val);
    }
    TreeNode* search(TreeNode* root, int val){
        if (root == nullptr) return nullptr;
        if (root->val == val) return root;

        TreeNode* left = search(root->left, val);
        if (left != nullptr)
            return left;

        return search(root->right, val);
    }
    void in(TreeNode* root){
        if(root == NULL) return;
        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
};