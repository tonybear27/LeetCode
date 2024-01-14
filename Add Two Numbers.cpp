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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* b1 = l1, *b2 = l2;
        long long num1 = 0, num2 = 0;
        long long base = 1;

        ListNode *ans = new ListNode;
        ListNode* head = ans;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0) {

            int num1, num2;
            if(l1 != nullptr) num1 = l1->val; 
            else num1 = 0;

            if(l2 != nullptr) num2 = l2->val;
            else num2 = 0;

            int num = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;

            ListNode *temp = new ListNode(num);
            head->next = temp;
            head = head->next;

            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }

        ans = ans->next;
        return ans;

    }
};