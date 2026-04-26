class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
public:
    Node* head;
    Node* tail;
    int sz;

    myQueue() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    bool isEmpty() {
        return sz == 0;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    void dequeue() {
        if (isEmpty()) return;

        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        sz--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return head->data;
    }

    int size() {
        return sz;
    }
};