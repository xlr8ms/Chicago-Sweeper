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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sab(nums, 0, nums.size()-1);
    }
    TreeNode* sab(vector<int>& v, int s, int e){
        int mid = s + (e-s)/2;
        if(s > e) return NULL;
        TreeNode* curr = new TreeNode(v[mid]);
        curr->left = sab(v, s, mid - 1);
        curr->right = sab(v, mid+1, e);
        return curr;
    }
};