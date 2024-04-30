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

    int traversal(TreeNode* root, int last) {

        int res = 0;

        if(!root->left && !root->right) return root->val + last; 

        if(root->left) res += traversal(root->left, (root->val + last) * 10 );
        if(root->right) res += traversal(root->right, (root->val + last) * 10);

        return res;
    }

    int sumNumbers(TreeNode* root) {
        // ios::sync_with_stdio(false);
        // cin.tie(nullptr);
        // cout.tie(nullptr);

        return  traversal(root, 0);
    }
};