/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head == NULL){
            Node* newNode = new Node(x);
            return newNode;
        }
        Node* temp = head;
        while(temp -> next){
            temp = temp-> next;
        }
        
        Node* newNode = new Node(x);
        temp -> next = newNode;
        
        return head;
    }
};