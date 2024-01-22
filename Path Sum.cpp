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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val == targetSum;

        bool f1 = hasPathSum(root->left, targetSum - root->val);
        bool f2 = hasPathSum(root->right, targetSum - root->val);

        return f1 || f2;    
    }
};