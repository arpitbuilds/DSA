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
        if(head->next==NULL || head==NULL){
            return NULL;
        }
        ListNode*cur=head;
        int l=0;
        while(cur){
            l++;
            cur=cur->next;
        }
        if(l==n){
            return head->next;
        }
        int k=l-n;
        cur=head;
        while(--k){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        return head;
    }
};