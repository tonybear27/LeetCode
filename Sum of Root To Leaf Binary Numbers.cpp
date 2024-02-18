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

    int ans = 0;
    int toDec(string s) {
        int n = 0;
        int base = 1;
        for(int i = s.length() - 1; i >= 0; i--) {
            n += (s[i] - '0') * base;
            base <<= 1;
        }

        return n;
    }

    void traversal(TreeNode* root, string s) {
        if(!root) return;


        s += to_string(root->val);
        
        if(!root->left && !root->right) ans += toDec(s);
        
        traversal(root->left, s);
        traversal(root->right, s);

        s.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        traversal(root, "");

        return ans;
    }
};