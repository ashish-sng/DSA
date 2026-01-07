// 226. Invert Binary Tree

//Iterative BFS Approach
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // swap children
            swap(curr->left, curr->right);

            // push children for further processing
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return root;
    }
};

// Recursive DFS Approach
TreeNode* invertTree(TreeNode* root) {
    // Base case: if root is null or a leaf node
    if (root == NULL) return NULL;
    
    // Store the left and right pointers
    TreeNode* leftChild = root->left;
    TreeNode* rightChild = root->right;
    
    // Swap the children
    root->left = invertTree(rightChild);
    root->right = invertTree(leftChild);
    
    return root;
}