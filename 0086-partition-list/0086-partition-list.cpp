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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* sp = small;
        ListNode* lp = large;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                sp->next = cur;
                sp = sp->next;
            } else {
                lp->next = cur;
                lp = lp->next;
            }
            cur = cur->next;
        }
        sp->next = large->next;
        lp->next = NULL;
        return small->next;
    }
};