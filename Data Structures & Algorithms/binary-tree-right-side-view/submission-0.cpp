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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);

        while(!q.empty()){
            int level_size = q.size();

            for(int i = 0; i < level_size - 1; ++i){
                TreeNode* curNode = q.front();
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
                q.pop();
            }
            ans.push_back(q.front()->val);
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);    
            q.pop();
        }

        return ans;
    }
};
