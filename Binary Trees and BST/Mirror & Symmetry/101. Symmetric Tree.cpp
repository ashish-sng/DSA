// 101. Symmetric Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        queue<TreeNode*> q;

        // push left and right together
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();

            // both null → symmetric at this level
            if (!left && !right)
                continue;

            // one null or values differ → not symmetric
            if (!left || !right || left->val != right->val)
                return false;

            // push children in mirror order
            q.push(left->left);
            q.push(right->right);

            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};