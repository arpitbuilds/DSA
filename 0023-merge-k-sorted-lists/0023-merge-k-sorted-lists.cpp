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

    struct cmp {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;   // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // push first node of each list
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // process heap
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next)
                pq.push(node->next);
        }

        return dummy->next;
    }
};
