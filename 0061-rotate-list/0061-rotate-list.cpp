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
        if(head==NULL || head->next==NULL){
            return head;
        }
        int l=1;
        ListNode*temp=head;
        while(temp->next!=NULL){
            l++;
            temp=temp->next;
        }
        k=k%l;
        if(k==0){
            return head;
        }
        int b=l-k;
        ListNode*prev=head;
        while(--b){
            prev=prev->next;
        }
        ListNode*newh=prev->next;
        temp->next=head;
        prev->next=NULL;
        return newh;
    }
};