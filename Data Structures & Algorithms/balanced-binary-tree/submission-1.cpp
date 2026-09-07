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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;

        int left = depth(root->left);
        if (left == -1) return -1; // 左子樹已不平衡，直接往上提早回傳

        int right = depth(root->right);
        if (right == -1) return -1; // 右子樹已不平衡，直接往上提早回傳

        if (std::abs(left - right) > 1) return -1; // 發現不平衡，回傳 -1

        return 1 + std::max(left, right);
    }
};
