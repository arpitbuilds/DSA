/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head;
        Node *cnode;
        while(temp){
            cnode=new Node(temp->val);
            cnode->next=temp->next;
            temp->next=cnode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            cnode=temp->next;
           cnode->random = temp->random ? temp->random->next : NULL;
            temp=temp->next->next;

        }
        temp=head;
        Node*dummy=new Node(0);
        Node*res=dummy;
        while(temp){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};