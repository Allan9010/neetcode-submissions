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
    int count;
    int goodNodes(TreeNode* root) {
        count = 0;
        dfs(root, INT_MIN);
        return count;
    }
    void dfs(TreeNode* node, int curmax){
        if(!node) return;
        if(node->val >= curmax){
            ++count;
            curmax = node->val;
        }
        dfs(node->left, curmax);
        dfs(node->right, curmax);
    }
};
//dfs
//單調
//紀錄當前有幾個