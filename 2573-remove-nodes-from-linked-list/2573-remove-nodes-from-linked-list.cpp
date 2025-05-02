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
    ListNode* rev(ListNode *head){
    ListNode *cur=head;
    ListNode *prev=NULL;
    while(cur!=NULL){
        ListNode *temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
        
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    head=rev(head);
    ListNode *prev2,*cur2;
    prev2=NULL;
    cur2=head;
    int maxi=head->val;
    while(cur2){
        maxi=max(maxi,cur2->val);
        if(maxi>cur2->val){
            prev2->next=cur2->next;
            cur2=cur2->next;
        }
        else{
            prev2=cur2;
            cur2=cur2->next;
        }
    }
   return rev(head);
    }
};