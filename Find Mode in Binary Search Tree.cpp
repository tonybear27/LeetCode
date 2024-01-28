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
    unordered_map<int, int> hash;

    void traversal(TreeNode* root) {
        if(!root) return;

        traversal(root->left);
        traversal(root->right);

        hash[root->val]++;
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        traversal(root);

        auto it = max_element(hash.begin(), hash.end(), 
        [](const auto& a, const auto& b){
            return a.second < b.second;
        });

        int ma = it->second;
        for(const auto num: hash) if(num.second == ma) ans.push_back(num.first);

        return ans;
    }
};