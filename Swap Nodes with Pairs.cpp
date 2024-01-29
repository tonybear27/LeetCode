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
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* current = head;
        while(current) {
            int num1 = current->val;
            int num2 = 0;
            if(current->next) {
                ListNode* nex = current->next;
                num2 = nex->val;
            }
            else break;

            current->val = num2;
            current = current->next;
            current->val = num1;
            current = current->next;
        }

        return head;
    }
};