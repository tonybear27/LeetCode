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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        for(int i = 0; i < preorder.size(); i++) mp[inorder[i]] = i;

        int idx = 0;
        return build(preorder, idx, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int& idx, int s, int e) {
        if(s > e) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);

        int pos = mp[root->val];

        root->left = build(preorder, idx, s, pos - 1);
        root->right = build(preorder, idx, pos + 1, e);

        return root;
    }
};