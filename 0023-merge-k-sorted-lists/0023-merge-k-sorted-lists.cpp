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
    ListNode*merge(ListNode*a,ListNode*b){
        ListNode*x=a;
        ListNode*y=b;
        ListNode*dummy=new ListNode(-1);
        ListNode*cur=dummy;
        while(x!=NULL && y!=NULL){
            if(x->val<=y->val){
            cur->next=x;
            x=x->next;
            cur=cur->next;
            }
            else{
                cur->next=y;
                y=y->next;
                cur=cur->next;
            }
        }
        while(x){
            cur->next=x;
            cur=cur->next;
            x=x->next;
        }
        while(y){
            cur->next=y;
            cur=cur->next;
            y=y->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin(),lists.begin()+2);
        }
        return lists.front();
    }
};