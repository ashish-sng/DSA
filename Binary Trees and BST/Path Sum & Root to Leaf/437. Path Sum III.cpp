// 437. Path Sum III

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
    int ans = 0;
    void dfs(TreeNode* root, int targetSum, long long sum) {
        if (root == NULL)
            return;

        sum += root->val;

        if (targetSum == sum) {
            ans++;
        }

        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
    }
    void traverse(TreeNode* root, int targetSum) {
        if (root == NULL)
            return;

        dfs(root, targetSum, 0);

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        traverse(root, targetSum);
        return ans;
    }
};