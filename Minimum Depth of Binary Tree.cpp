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
    void auxiliary(TreeNode* root, int& ans, int temp) {
        
        if(!root) return;

        if(!root->left && !root->right) {
            ans = min(ans, temp);
            return;
        } 

        temp++;
        auxiliary(root->left, ans, temp);
        auxiliary(root->right, ans, temp);
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int temp = 1, ans = INT_MAX;
        auxiliary(root, ans, temp);
        return ans;
    }
};