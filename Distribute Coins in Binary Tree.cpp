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
    int distributeCoins(TreeNode* root, TreeNode* parent = nullptr) {
        if(!root) return 0;

        int move = distributeCoins(root->left, root) + distributeCoins(root->right, root);

        int give = root->val - 1;
        if(parent) parent->val += give;

        move += abs(give);

        return move;
    }
};