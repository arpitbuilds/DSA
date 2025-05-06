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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
       ListNode*curr=head;
       int l=0;
       while(curr){
        l++;
        curr=curr->next;

       } 
       if(l==n){
        head=head->next;
        return head;
       }
       int k=l-n;
       ListNode *temp=head;
       while(--k){
        temp=temp->next;
       }
       temp->next=temp->next->next;
       return head;
    }
};