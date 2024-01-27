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
    int sum = 0;

    void traversal(TreeNode* root, bool flag) {
        if(!root) return;

        if(!root->left && !root->right && flag) sum += root->val;

        traversal(root->left, 1);
        traversal(root->right, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root, 0);    

        return sum;
    }
};