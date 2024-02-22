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
    int cnt = 0;
    void dfs(TreeNode* root, int max) {
        if(!root) return;

        if(root->val >= max) {
            cnt++;
            max = root->val;
        }

        dfs(root->left, max);
        dfs(root->right, max);
    }

    int goodNodes(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int max = INT_MIN;
        dfs(root, max);
        return cnt;
    }
};