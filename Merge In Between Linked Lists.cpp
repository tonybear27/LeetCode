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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        ListNode* ptr = list1;
        for(int i = 0; i < a - 1; i++) ptr = ptr->next;

        ListNode* ptr2 = ptr->next;
        for(int i = 0; i < b - a + 1; i++) ptr2 = ptr2->next;

        ptr->next = list2;
        while(list2->next) list2 = list2->next;

        list2->next = ptr2;

        return list1;
    }
};