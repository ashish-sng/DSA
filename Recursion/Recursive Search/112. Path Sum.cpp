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
    bool backTrack(TreeNode* root, int currSum) {
        if (!root)
            return false;
        if (!root->left && !root->right && currSum == root->val)
            return true;

        bool ls = backTrack(root->left, currSum - root->val);
        bool rs = backTrack(root->right, currSum - root->val);

        return ls || rs;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return backTrack(root, targetSum);
    }
};