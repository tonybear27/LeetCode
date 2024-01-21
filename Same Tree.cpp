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

    void preorder(TreeNode* root, vector<int>& ans) {

        if(root == nullptr) {
            ans.push_back(-1);
            return;
        };

        ans.push_back(root->val);
        preorder(root->left, ans);

        preorder(root->right, ans);
    }

    bool check(vector<int> l1, vector<int> l2) {

        if(l1.size() != l2.size()) return 0;
        for(int i = 0, j = 0; i < l1.size(); i++, j++) if (l1[i] != l2[j]) return 0;

        return 1;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans1, ans2;

        preorder(p, ans1);
        preorder(q, ans2);

        return check(ans1, ans2);
    }
};