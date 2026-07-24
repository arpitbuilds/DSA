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
   ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode*dumh=new ListNode(0);
        ListNode*a=list1;
        ListNode*b=list2;
        ListNode*dummy=dumh;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                dummy->next=a;
                a=a->next;
                dummy=dummy->next;
            }
            else{
                dummy->next=b;
                b=b->next;
                dummy=dummy->next;
            }
        }
        while(a!=NULL){
            dummy->next=a;
            a=a->next;
            dummy=dummy->next;
        }
        while(b){
            dummy->next=b;
            b=b->next;
            dummy=dummy->next;
        }
        return dumh->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.empty()){
        return NULL;
      }
      while(lists.size()>1){
        lists.push_back(merge(lists[0],lists[1]));
        lists.erase(lists.begin(),lists.begin()+2);
      }
      return lists[0];
    }
};