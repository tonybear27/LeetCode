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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* preLeft = dummy;

        for(int i = 1; i < left; i++) preLeft = preLeft->next;

        ListNode* cur = preLeft->next;
        ListNode* prev = nullptr;
        for(int i = left; i <= right; i++) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        preLeft->next->next = cur;
        preLeft->next = prev;

        return dummy->next;    
    }
};