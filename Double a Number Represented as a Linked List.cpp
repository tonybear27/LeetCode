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
        ListNode* prev = nullptr, *nxt = nullptr;
        ListNode* cur = head;

        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* rev = reverse(head);
        ListNode* ans = rev;
        ListNode* cur = rev;
        int carry = 0;

        while(cur) {
            cur->val = cur->val * 2 + carry;
            carry = cur->val / 10;
            cur->val %= 10;

            cur = cur->next;
        }

        ans = reverse(ans);
        ListNode* node = new ListNode(carry);
        node->next = ans;

        return carry? node: ans;
    }
};