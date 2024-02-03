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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode;
        ListNode* large = new ListNode;

        ListNode* smallT = small;
        ListNode* largeT = large;

        while(head) {
            if(head->val < x) {
                smallT->next = head;
                smallT = smallT->next;
            }
            else {
                largeT->next = head;
                largeT = largeT->next;
            }

            head = head->next;
        }

        smallT->next = large->next;
        largeT->next = nullptr;

        return small->next;
    }
};