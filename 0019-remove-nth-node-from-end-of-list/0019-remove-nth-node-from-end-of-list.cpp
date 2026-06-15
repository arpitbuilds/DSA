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
        vector<int>temp;
        int cnt=0;
        ListNode*cur=head;
        while(cur){
            cnt++;
            cur=cur->next;
        }
        cur=head;
        int k=0;
        while(cur){
            if(k!=cnt-n){
            temp.push_back(cur->val);
            }
            cur=cur->next;
            k++;
        }
        ListNode*dum=new ListNode(0);
        ListNode*x=dum;
        for(int i=0;i<temp.size();i++){
            x->next=new ListNode(temp[i]);
            x=x->next;
        }
        return dum->next;
    }
};