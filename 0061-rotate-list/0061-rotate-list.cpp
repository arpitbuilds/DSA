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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode*temp=head;
        int l=1;
        while(temp->next!=NULL){
            l++;
            temp=temp->next;
        }
         k=k%l;
        if(k==0){
            return head;
        }
        int b=l-k;
        ListNode*cur=head;
        while(--b){
            cur=cur->next;
        }
        ListNode*newh=cur->next;
        cur->next=NULL;
        temp->next=head;
        cur->next=NULL;
        return newh;
    }
};