// 94. Binary Tree Inorder Traversal

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
    void inOrderTraversal(TreeNode* root){
        if(root == NULL) return;

        if(root->left) inOrderTraversal(root->left);
        ans.push_back(root->val);
        if(root->right) inOrderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrderTraversal(root);
        return ans;
    }
};