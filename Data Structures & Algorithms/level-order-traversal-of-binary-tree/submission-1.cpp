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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelsize = q.size();
            int level = ans.size();
            ans.push_back(vector<int>());

            for(int i = 0; i < levelsize; ++i){
                TreeNode *node = q.front();
                ans[level].push_back(node->val);
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);

                q.pop();
            }
        }

        return ans;
    }
};
