// 124. Binary Tree Maximum Path Sum

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
    int ans = INT_MIN;
    int calculateMaxSum(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftGain = max(0, calculateMaxSum(root->left));
        int rightGain = max(0, calculateMaxSum(root->right));

        ans = max(ans, root->val + leftGain + rightGain);

        return root->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        calculateMaxSum(root);
        return ans;
    }
};