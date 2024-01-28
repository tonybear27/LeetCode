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
    int ans, m;

    void traversal(TreeNode* root) {
        if(!root) return;

        traversal(root->left);
        ans = min(ans, root->val - m);
        m = root->val;
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        m = -100000;
        traversal(root);
        return ans;
    }
};