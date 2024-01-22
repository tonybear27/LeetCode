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
    
    int auxiliary(TreeNode* root, bool& flag) {
        if(root == nullptr) return 0;

        int a = auxiliary(root->left, flag);
        int b = auxiliary(root->right, flag);
        int diff = abs(a - b);

        if(diff > 1) flag = 1; 

        return max(a + 1, b + 1);
    }

    bool isBalanced(TreeNode* root) {
        bool flag = 0;
        auxiliary(root, flag);
        return !flag; 
    }
};