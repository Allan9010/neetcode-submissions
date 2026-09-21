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
    bool isValidBST(TreeNode* root) {
        return recursive(root, INT_MAX, INT_MIN);
    }
    bool recursive(TreeNode* root, int max_val, int min_val){
        if(!root) return true;
        if(root->val >= max_val || root->val <= min_val){
            return false;
        }
        
        bool checkleft = recursive(root->left, root->val, min_val);
        bool checkright = recursive(root->right, max_val, root->val);
        
        return checkleft && checkright;
    }
};
