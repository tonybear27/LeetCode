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
    void traversal(TreeNode* root, vector<int>& node) {
        if(!root) return;

        traversal(root->left, node);
        node.push_back(root->val);
        traversal(root->right, node);
    }

    TreeNode* build(vector<int>& root, int i, int j) {
        if(i > j) return nullptr;

        int mid = (i + j) / 2;
        TreeNode *node = new TreeNode(root[mid]);

        node->left = build(root, i, mid - 1);
        node->right = build(root, mid + 1, j);

        return node; 
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int> node;
        traversal(root, node);

        TreeNode* tree = build(node, 0, node.size() - 1);

        return tree;
    }
};