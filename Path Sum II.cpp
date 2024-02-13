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
    vector<vector<int>> ans;
    void traversal(TreeNode* root, vector<int> sum, int cur, int target) {
        if(root == nullptr) return;
         
        sum.push_back(root->val);
        cur += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(cur == target) ans.push_back(sum);
        }

        traversal(root->left, sum, cur, target);
        traversal(root->right, sum, cur, target);

        sum.pop_back();
        cur -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> sum;
        traversal(root, sum, 0, targetSum);

        return ans;
    }
};