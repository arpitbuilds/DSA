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
int gcd(int a, int b) {

    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // If both numbers are equal
    if (a == b)
        return a;

    // If a is greater
    if (a > b)
      return gcd(a - b, b);


	// If b is greater
    return gcd(a, b - a);
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode *a=head;
    ListNode*b=head->next;
    while(b){
     int gcdv=gcd(a->val,b->val);
     ListNode *gcdnode=new ListNode(gcdv);

     a->next=gcdnode;
     gcdnode->next=b;

     a=b;
     b=b->next;
    }
  return  head;
    }
};