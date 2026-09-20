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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
    int dfs(TreeNode* node, int curmax){
        if(!node) return 0;
        
        int count = 0;
        if(node->val >= curmax){
            ++count;
            curmax = node->val;
        }
        count += dfs(node->left, curmax);
        count += dfs(node->right, curmax);
    
        return count;
    }
};
//dfs
//單調
//紀錄當前有幾個