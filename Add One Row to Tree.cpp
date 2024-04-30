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
    void add(TreeNode* root, int d, int depth, int val) {
        if(root == nullptr) return;

        if(d + 1 == depth) {
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);

            l->left = root->left;
            root->left = l;

            r->right = root->right;
            root->right = r;
        }

        add(root->left, d + 1, depth, val);
        add(root->right, d + 1, depth, val);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) {
            if(depth == 1)
                return new TreeNode(val);
        } 

        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;

            return node;
        }

        add(root, 1, depth, val);

        return root;
    }
};