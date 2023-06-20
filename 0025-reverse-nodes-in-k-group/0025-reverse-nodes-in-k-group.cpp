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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode *pre = dummy, *nxt = dummy, *cur = dummy;
        int count = 0;

        // Count the number of nodes
        while (cur->next != nullptr) {
            cur = cur->next;
            count++;
        }

        // Reverse in groups of size k
        while (count >= k) {
            cur = pre->next;
            nxt = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            pre = cur;
            count -= k;
        }

        return dummy->next;
    }
};
