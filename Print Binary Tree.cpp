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

    void traversal(TreeNode* root, vector<vector<string>>& ans, int row, int col, int height) {
        if(!root) return;

        ans[row][col] = to_string(root->val);

        int l = col - pow(2, height - row - 1);
        int r = col + pow(2, height - row - 1);

        traversal(root->left, ans, row + 1, l, height);
        traversal(root->right, ans, row + 1, r, height);

    }

    int treeHeight(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = treeHeight(root) - 1;
        int width = pow(2, height + 1) - 1;

        vector<vector<string>> ans(height + 1, vector<string>(width, ""));

        int row = 0;
        int col = (width - 1) / 2;

        traversal(root, ans, row, col, height);

        return ans;    
    }
};