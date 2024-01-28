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
    bool flag = 0;

    void auxiliary(TreeNode* root, TreeNode* sub) {
        if(!root) return;
        if(flag) return; 
        
        auxiliary(root->left, sub);
        auxiliary(root->right, sub);
        if(!flag)
            flag = isIdentical(root, sub);
        return;
    }

    bool isIdentical(TreeNode* root, TreeNode* sub) {
        if(!root && !sub) return 1;
        else if(!root || !sub) return 0;

        return (root->val == sub->val) && isIdentical(root->left, sub->left) && isIdentical(root->right, sub->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        auxiliary(root, subRoot);
        return flag;
    }
};