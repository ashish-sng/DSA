// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Preorder gives root, inorder gives boundary.

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
    int preorderIndex = 0;
    unordered_map<int, int> inOrderIndex;
    TreeNode* build(vector<int>& preorder, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd)
            return NULL;

        int rootVal = preorder[preorderIndex++];

        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = inOrderIndex[rootVal];

        root->left = build(preorder, inorderStart, rootIndex - 1);

        root->right = build(preorder, rootIndex + 1, inorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            inOrderIndex[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};