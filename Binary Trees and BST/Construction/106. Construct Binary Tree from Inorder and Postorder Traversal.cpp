// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    int postIndex;
    unordered_map<int, int> inorderIndex;
    TreeNode* build(vector<int>& postorder, int start, int end) {
        if (start > end)
            return NULL;

        int rootVal = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootVal);

        int rootInorderIndex = inorderIndex[rootVal];

        root->right = build(postorder, rootInorderIndex + 1, end);
        root->left = build(postorder, start, rootInorderIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }
};