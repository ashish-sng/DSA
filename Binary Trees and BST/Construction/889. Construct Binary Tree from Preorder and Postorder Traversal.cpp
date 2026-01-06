// 889. Construct Binary Tree from Preorder and Postorder Traversal

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
    int preIndex = 0;
    unordered_map<int, int> postIndex;
    TreeNode* build(vector<int>& preorder, vector<int>& postorder,
                    int postStart, int postEnd) {
        if (postStart > postEnd)
            return nullptr;

        int rootVal = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootVal);

        if (postStart == postEnd)
            return root;

        int leftChildVal = preorder[preIndex];

        int leftChildIndex = postIndex[leftChildVal];

        root->left = build(preorder, postorder, postStart, leftChildIndex);
        root->right =
            build(preorder, postorder, leftChildIndex + 1, postEnd - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }

        return build(preorder, postorder, 0, postorder.size() - 1);
    }
};