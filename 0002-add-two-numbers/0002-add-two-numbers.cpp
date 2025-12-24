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
        int sum=0;
        int c=0;
        ListNode*t1=l1;
        ListNode*t2=l2;
        while(t1 || t2 || c ){
            sum=c;
            if(t1){
                sum+=t1->val;
                t1=t1->next;
            }
            if(t2){
                sum+=t2->val;
                t2=t2->next;
            }
            cur->next=new ListNode(sum%10);
            c=sum/10;
            cur=cur->next;
        }
        return dummy->next;
    }
};