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
    ListNode* swapNodes(ListNode* head, int k) {
     
        if(head==NULL || head->next==NULL){
            return head;
        }
           ListNode *a =head;
        ListNode *b=head;
        while(--k){
            a=a->next;
        }
        ListNode*kth=a;
        a=a->next;
        while(a){
            a=a->next;
            b=b->next;
        }
        swap(kth->val,b->val);
        return head;
    }
};