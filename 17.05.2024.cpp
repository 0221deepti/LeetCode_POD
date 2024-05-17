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
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        // If the root is null, return null
        if (!root) return nullptr;
        
        // Recursively call the function on the left and right children
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        // Check if the current node is a leaf and has the target value
        if (!root->left && !root->right && root->val == target) {
            // Delete the node by returning nullptr
            return nullptr;
        }
        
        // Return the current node
        return root;
        
    }
};
