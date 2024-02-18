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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(!root1 && !root2) return 1;

        if(root1 && !root2 || !root1 && root2) return 0;

        if(root1->val != root2->val) return 0;

        if(root1->left && root2->left && root1->right && root2->right) {
            if(root1->left->val == root2->right->val && root1->right->val == root2->left->val) swap(root1->left, root1->right);
        }

        if((root1->left && root2->right && root1->left->val == root2->right->val) || (root2->left && root1->right && root2->left->val == root1->right->val)) swap(root1->right, root1->left);

        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    }
};