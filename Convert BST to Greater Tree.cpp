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
    void traversal(TreeNode* root, int& sum) {
        if(root == nullptr) return;

        traversal(root->right, sum);
        int temp = root->val;
        root->val += sum;
        sum += temp;
        traversal(root->left, sum);

    }

    TreeNode* convertBST(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int sum = 0;
        traversal(root, sum);

        return root;        
    }
};