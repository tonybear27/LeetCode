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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode;
        ListNode* head = res;
        ListNode* left = l1;
        ListNode* right = l2;

        while(left && right) {
            if(left->val <= right->val) {
                head->next = left;
                head = head->next;
                left = left->next;
            }
            else {
                head->next = right;
                head = head->next;
                right = right->next;
            }
        }

        if(left) head->next = left;
        if(right) head->next = right;

        return res->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];

        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++) head = merge(head, lists[i]);

        return head;
    }
};