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

    TreeNode* auxiliary(vector<int>& nums, int low, int high) {

        if(low <= high) {
            int mid = (low + high) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = auxiliary(nums, low, mid - 1);
            root->right = auxiliary(nums, mid + 1, high);
            return root;
        }

        return nullptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return auxiliary(nums, 0, nums.size() - 1);      
    }
};