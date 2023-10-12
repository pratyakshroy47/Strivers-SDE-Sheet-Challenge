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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];

        vector<ListNode*> lists1(lists.begin(), lists.begin() + n/2);
        vector<ListNode*> lists2(lists.begin() + n/2, lists.end());

        ListNode* l1 = mergeKLists(lists1);
        ListNode* l2 = mergeKLists(lists2);

        if(l1 == NULL) return l2;

        ListNode* ret = l1;

        while(l2 != NULL) {
            if(l1->val > l2->val) swap(l1->val, l2->val);

            while(l1->next && l1->next->val < l2->val) l1 = l1->next;

            ListNode* temp = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l2 = temp;
        }
        return ret;
    }
};