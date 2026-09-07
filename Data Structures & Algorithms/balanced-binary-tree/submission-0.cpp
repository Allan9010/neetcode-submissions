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
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        depth(root);
        return ans;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        if(!ans) return 0;

        int left = depth(root->left);
        int right = depth(root->right);
        if(std::abs(left - right) > 1) ans = false;

        return 1 + max(left, right);
    }
};
