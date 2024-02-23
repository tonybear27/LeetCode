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
    vector<int> ans;
    bool dfs(TreeNode* root, vector<int>& voyage, int &idx) {
        if(!root) return 1;
        if(root->val != voyage[idx]) return 0;
        
        idx++;

        bool flag = dfs(root->left, voyage, idx) && dfs(root->right, voyage, idx);

        if(flag) return 1;

        ans.push_back(root->val);

        return dfs(root->right, voyage, idx) && dfs(root->left, voyage, idx);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = 0;
        if(dfs(root, voyage, idx)) return ans;

        return {-1};
    }
};