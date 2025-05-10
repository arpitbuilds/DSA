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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *cur=dummy;
        int c=0;
        int sum=0;
        while(temp1!=NULL || temp2!=NULL || c!=0){
            sum=c;
            if(temp1!=NULL){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            c=sum/10;
            ListNode *node=new ListNode(sum%10);
            cur->next=node;
            cur=cur->next;


        }

        return dummy->next;
    }
};