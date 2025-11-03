class myQueue {
public:
    int arr[100];
    int front;
    int rear;
    int size;

    myQueue(int n) {
        size = n;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int x) {
        if (isFull()) return;

        // if queue is empty
        if (isEmpty()) {
            front = rear = 0;
            arr[rear] = x;
        } 
        else {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) return;

        // if only one element
        if (front == rear) {
            front = rear = -1;
        } 
        else {
            front = (front + 1) % size;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};
