/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
  Node*top;
  int cnt;
    myStack() {
        // Initialize your data members
        top=NULL;
        cnt=0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node*it=new Node(x);
        it->next=top;
        top=it;
        cnt++;
    }

    void pop() {
        // Removes the top element of the stack
        if(isEmpty()){
            return ;
        }
        Node*temp=top;
        top=top->next;
        delete temp;
        cnt--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty()){
            return -1;
        }
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return cnt;
    }
};