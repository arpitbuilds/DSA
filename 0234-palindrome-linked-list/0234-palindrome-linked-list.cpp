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
    ListNode *rev(ListNode *h){
        ListNode*cur=h;
        ListNode*prev=NULL;
        while(cur){
            ListNode*next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *x=rev(slow);
        slow->next=NULL;
        while(x){
            if(x->val!=head->val){
                return false;
            }
            head=head->next;
            x=x->next;
        }
        return true;
    }
};