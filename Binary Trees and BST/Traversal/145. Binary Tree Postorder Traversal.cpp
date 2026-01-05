// 145. Binary Tree Postorder Traversal

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
    private:
    vector<int> ans;
public:
    void preOrderTraversal(TreeNode* root){
        if(root == NULL) return;

        ans.push_back(root->val);
        if(root->left) preOrderTraversal(root->left);
        if(root->right) preOrderTraversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrderTraversal(root);
        return ans;
    }
};