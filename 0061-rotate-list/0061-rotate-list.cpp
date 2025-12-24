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
        ListNode*cur=head;
        int l=1;
        while(cur->next!=NULL){
            l++;
            cur=cur->next;
        }
        k=k%l;
        if(k==0){
            return head;
        }
        int b=l-k;
        ListNode*temp=head;
        while(--b){
            temp=temp->next;
        }
        ListNode*newh=temp->next;
        temp->next=NULL;
        cur->next=head;
        return newh;
    }
};