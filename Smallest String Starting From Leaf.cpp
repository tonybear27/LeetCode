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
    string ans;
    void traversal(TreeNode* root, string s) {
        if(root == nullptr) return;

        s += root->val + 'a';
        if(root->left == nullptr && root->right == nullptr) {
            reverse(s.begin(), s.end());
            if(ans == "") ans = s;
            else ans = min(ans, s);
            reverse(s.begin(), s.end());
        }

        traversal(root->left, s);
        traversal(root->right, s);

        s.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        traversal(root, "");
        return ans;
    }
};