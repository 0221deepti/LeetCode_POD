class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
    
private:
    int dfs(TreeNode* node, int& moves) {
        if (!node) {
            return 0;
        }
        
        // Calculate the balance of coins for the left and right subtrees
        int left_balance = dfs(node->left, moves);
        int right_balance = dfs(node->right, moves);
        
        // Current node's total balance is its own coins plus the balance of its children
        int total_balance = node->val + left_balance + right_balance - 1;
        
        // Update the total moves needed with the absolute value of the current node's balance
        moves += abs(total_balance);
        
        // Return the total balance for the current node to its parent
        return total_balance;
    }
};
