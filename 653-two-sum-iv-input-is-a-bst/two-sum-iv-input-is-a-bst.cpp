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
    bool findTarget(TreeNode* root, int k) {
        in(root);
        int s = 0, e = v.size()-1;
        while(s<e){
            if(v[s] + v[e] == k) return 1;
            if(v[s] + v[e] < k){
               s++; 
            }
            else if(v[s] + v[e] > k){
                e--;
            }
        }
        return 0;
    }
    void in(TreeNode* root){
        if(root == NULL) return;

        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
};