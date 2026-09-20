class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node*next;
        Node*prev;
        Node(int k,int v){
            key=k;
            val=v;
        }

    };
    int cap;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    unordered_map<int,Node*>mpp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertatfront(Node*node){
        Node*temp=head->next;
        head->next=node;
        node->next=temp;
        temp->prev=node;
        node->prev=head;

    }
    void del(Node*node){
        Node*prevn=node->prev;
        Node*nextn=node->next;
        prevn->next=nextn;
        nextn->prev=prevn;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node*node=mpp[key];
            del(node);
            insertatfront(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*node=mpp[key];
            node->val=value;
            del(node);
            insertatfront(node);
        }
        else{
            if(mpp.size()==cap){
                Node*lru=tail->prev;
                mpp.erase(lru->key);
                del(lru);
                delete lru;
            }
            Node*node=new Node(key,value);
            insertatfront(node);
            mpp[key]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */