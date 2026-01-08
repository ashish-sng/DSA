// 129. Sum Root to Leaf Numbers

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
    int addSum(TreeNode* root, int sum = 0) {
        if (!root)
            return 0;

        sum = sum * 10 + root->val;

        if (!root->left && !root->right) {
            return sum;
        }

        int lsum = addSum(root->left, sum);
        int rsum = addSum(root->right, sum);

        return lsum + rsum;
    }
    int sumNumbers(TreeNode* root) { return addSum(root); }
};