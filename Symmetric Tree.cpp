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

    bool auxiliary(TreeNode* left, TreeNode* right) {
        if(!left || !right) return left == right;
        if(left->val != right->val) return 0;

        return auxiliary(left->left, right->right) && auxiliary(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        return auxiliary(left, right);
    }
};