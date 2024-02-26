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
typedef long long ll;
public:
    ll widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        ll ans = 0;

        while(!q.empty()) {
            int size = q.size();
            ll levelMin = q.front().second;
            ll left, right;

            for(int i = 0; i < size; i++) {
                ll current = q.front().second - levelMin;
                cout << current << ' ';
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) left = current;
                if(i == size - 1) right = current;

                if(node->left) q.push({node->left, current * 2 + 1});
                if(node->right) q.push({node->right, current * 2 + 2});
            }
            puts("");
            ans = max(ans, right - left + 1);
        } 

        return ans;
    }
};