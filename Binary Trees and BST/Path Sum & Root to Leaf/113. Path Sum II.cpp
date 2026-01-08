// 113. Path Sum II

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
    vector<int> currRow;
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return ans;
        }

        currRow.push_back(root->val);

        if (!root->left && !root->right && targetSum == root->val) {
            ans.push_back(currRow);
        }

        pathSum(root->left, targetSum - root->val);

        pathSum(root->right, targetSum - root->val);

        currRow.pop_back();

        return ans;
    }
};