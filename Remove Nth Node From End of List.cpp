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
    
    int length(ListNode* root) {
        int len = 0;
        ListNode* head = root;
        while(head) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if(len == 1) return nullptr;
        if(len == n) return head->next;

        int cnt = 0;
        ListNode* ptr = head;
        
        /*** Find the position ***/
        while(cnt < len - n - 1) {
            ptr = ptr->next;
            cnt++;
        }

        ptr->next = ptr->next->next;

        return head;
    }
};