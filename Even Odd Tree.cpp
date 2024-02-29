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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int turn = 0;
        while(!q.empty()) {
            int size = q.size();
            int prev = -1;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(turn % 2 == 0 && node->val % 2 == 0) return 0;
                else if(turn % 2 == 1 && node->val % 2 == 1) return 0;
                
                if(turn % 2 == 0 && i != 0) {
                    if(node->val <= prev) return 0; 
                }
                else if(turn % 2 == 1 && i != 0) if(node->val >= prev) return 0;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                prev = node->val; 
            }

            turn++;
        }

        return 1;
    }
};