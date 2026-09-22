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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int count = 0;
        stack<TreeNode*> s;
        s.push(cur);

        while(cur != nullptr || !s.empty()){
            while(cur != nullptr){
                s.push(cur);
                cur = cur->left;
            }
            TreeNode* temp = s.top();
            s.pop();
            if(++count == k) return temp->val;
            cur = temp->right;
        }
        return -1;
    }
};
