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
        ListNode*dummy=new ListNode(0);
        ListNode*cur=dummy;
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        int c=0;
        int sum=0;
        while(temp1 || temp2 || c){
            sum=c;
            if(temp1){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            cur->next=new ListNode(sum%10);
            c=sum/10;
            cur=cur->next;
        }
        return dummy->next;
    }
};