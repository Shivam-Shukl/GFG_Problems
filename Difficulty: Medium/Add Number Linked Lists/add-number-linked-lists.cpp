/*
class Node {
  public:
    long long data;
    Node* next;
    Node(long long x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  
    // reverse
    Node* rev(Node* head) {
        Node* prev = nullptr;
        Node* temp = head;
    
        while (temp) {
            Node* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;   // new head
    }
    
    // trim
    void print(Node* head){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp =temp->next;
        }
     
    }
    Node* trim(Node* head){
        Node* temp = head;
 
        while(temp && temp -> data == 0 ){
            temp = temp -> next;
        }
        return temp;
    }
    Node* add(Node* head1 , Node* head2){
        int carry = 0;
        Node* head3 = new Node(-1);
        Node* ans = head3;
        
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1 && temp2){
            int d = temp1 -> data + temp2 -> data + carry;
            carry = d / 10;
            d = d % 10;
            
            Node* newNode = new Node(d);
            ans -> next  = newNode;
            ans = ans -> next;
            
            temp1 = temp1 ->next;
            temp2 = temp2 -> next;
        }
        while(temp1){
            int d= temp1 -> data + carry;
            carry = d/10;
            d = d % 10;
            
            Node* newNode = new Node(d);
            ans -> next  = newNode;
            ans = ans -> next;
            
            temp1 = temp1 ->next;
        }
        while(temp2){
            int d = temp2 -> data + carry;
            carry = d/10;
            d = d % 10;
            
            Node* newNode = new Node(d);
            ans -> next  = newNode;
            ans = ans -> next;
            
            temp2 = temp2 ->next;
        }
        if(carry != 0){
            
            Node* newNode = new Node(carry);
            ans -> next  = newNode;
            ans = ans -> next;
        }
        if(head3 -> next){
            return head3->next;
        }else{
            return nullptr;
        }
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        
        // trim
        head1 = trim(head1);
        head2 = trim(head2);
        // rev
        head1 = rev(head1);
        head2 = rev(head2);
        // solution 
        Node* head3 = add(head1,head2);
        head3 = rev(head3);
        
       
        return head3;
        
    }
};