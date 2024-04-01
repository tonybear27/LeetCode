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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur = head;
        while(cur) {
            st.push(cur);
            cur = cur->next;
        }

        cur = head;
        unordered_map<ListNode*, bool> isVisited;

        while(1) {
            ListNode* last = st.top();
            st.pop();
            ListNode* next = cur->next;
            isVisited[cur] = 1;

            if(isVisited[last]) {
                cur->next = nullptr;
                break;
            }

            cur->next = last;
            isVisited[last] = 1;
            cur = cur->next;
            if(isVisited[next]) {
                cur->next = nullptr;
                break;
            }

            cur->next = next;
            cur = cur->next;
        }
    }
};