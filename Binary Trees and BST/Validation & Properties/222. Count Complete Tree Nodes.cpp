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
    // find height by going left
    int getHeight(TreeNode* root) {
        int height = 0;
        while (root->left) {
            height++;
            root = root->left;
        }
        return height;
    }

    // check if a node at index `idx` exists in last level
    bool exists(TreeNode* root, int idx, int height) {
        int left = 0;
        int right = (1 << height) - 1;

        for (int i = 0; i < height; i++) {
            int mid = left + (right - left) / 2;
            if (idx <= mid) {
                root = root->left;
                right = mid;
            } else {
                root = root->right;
                left = mid + 1;
            }
        }
        return root != nullptr;
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        // height of tree
        int height = getHeight(root);

        // nodes in all fully filled levels
        int fullLevelsCount = (1 << height) - 1;

        // binary search on last level
        int left = 0;
        int right = (1 << height) - 1;
        int lastLevelNodes = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (exists(root, mid, height)) {
                lastLevelNodes = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // total nodes
        return fullLevelsCount + lastLevelNodes;
    }
};
