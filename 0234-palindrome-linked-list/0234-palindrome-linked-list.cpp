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
    ListNode* rev(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur) {
            ListNode* aage = cur->next;
            cur->next = prev;
            prev = cur;
            cur = aage;
        }
        return prev;
    }
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* mid = middle(head);
        ListNode* x = rev(mid);
        ListNode* cur = x;
        mid->next=NULL;
        ListNode* temp=head;
        while (cur && temp) {
            if (temp->val != cur->val) {
                return false;
            }
            cur = cur->next;
            temp = temp->next;
        }

        return true;
    }
};