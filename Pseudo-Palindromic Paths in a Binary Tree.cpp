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
    void traversal(TreeNode* root, bitset<10> p) {
        if(!root) return;

        int val = root->val;
        p[val] = ~p[val];

        if(root->left == nullptr && root->right == nullptr) if(p.count() <= 1) cnt++;

        traversal(root->left, p);
        traversal(root->right, p);

    }

    int pseudoPalindromicPaths (TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        bitset<10> p;

        traversal(root, p);

        return cnt;      
    }
};