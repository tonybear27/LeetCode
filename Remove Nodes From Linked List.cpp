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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        while(head) {
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* rev = reverse(head);
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        int m = rev->val;

        while(rev) {
            while(rev && rev->val < m) rev = rev->next;

            if(!rev) {
                temp->next = nullptr;
                break;
            }

            m = rev->val;
            temp->next = rev;
            temp = temp->next;
            rev = rev->next;
        }

        return reverse(ans->next);
    }
};