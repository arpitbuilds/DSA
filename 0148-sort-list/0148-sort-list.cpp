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
    ListNode* mergelist(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                cur->next = temp1;
                cur = cur->next;
                temp1 = temp1->next;
            } else {
                cur->next = temp2;
                cur = cur->next;
                temp2 = temp2->next;
            }
        }
        while (temp1) {
            cur->next = temp1;
            temp1 = temp1->next;
            cur = cur->next;
        }
        while (temp2) {
            cur->next = temp2;
            temp2 = temp2->next;
            cur = cur->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode*head1=sortList(head);
        ListNode*head2=sortList(slow);
        return mergelist(head1,head2);
    }
};