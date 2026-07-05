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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*check=head;
        for(int i=0;i<k;i++){
            if(check==NULL){
                return head;
            }
            check=check->next;
        }
        ListNode*prev=NULL;
        ListNode*cur=head;
        for(int i=0;i<k;i++){
            ListNode*aage=cur->next;
            cur->next=prev;
             prev=cur;
            cur=aage;
           
        }
        head->next=reverseKGroup(cur,k);
        return prev;

    }
};