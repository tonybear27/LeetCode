/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next) {
            int num1 = cur->val;
            int num2 = cur->next->val;

            cur->val = num2;
            cur = cur->next;

            cur->val = num1;
            cur = cur->next;
        }

        return head;
    }
};
