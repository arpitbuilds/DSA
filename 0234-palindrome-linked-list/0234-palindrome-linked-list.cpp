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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        if (head == NULL || head->next == NULL) {
            return head;
        }
        while (cur) {
            ListNode* aage = cur->next;
            cur->next = prev;
            prev = cur;
            cur = aage;
        }
        return prev;
    }
    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode*x=mid(head);
        ListNode*rev=reverseList(x);
        x->next=NULL;
        ListNode*cur=head;
        while(cur && rev){
            if(cur->val!=rev->val){
                return false;
            }
            cur=cur->next;
            rev=rev->next;
        }
return true;
    }
};