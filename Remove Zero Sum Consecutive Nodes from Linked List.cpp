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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode;
        ListNode* cur = head;
        unordered_map<int, ListNode*> mp;
        int prefix = 0;
        mp[0] = dummy;
        dummy->next = head;

        while(cur) {
            prefix += cur->val;
            if(mp.find(prefix) != mp.end()) {
                ListNode* del = mp[prefix]->next;
                int temp = prefix + del->val;

                while(del != cur) {
                    mp.erase(temp);
                    del = del->next;
                    temp += del->val;
                }
                mp[prefix]->next = cur->next;
            }
            else mp[prefix] = cur;

            cur = cur->next;
        }

        return dummy->next;
    }
};