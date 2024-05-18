#include <iostream>
using namespace std;


// Linked List Node
class Node {
    public:
        int data;
        Node* next;

        Node(int d){
            this->data = d;
            this->next = NULL;
        }
        
};

// inset at node first postion
void InsertAtFirst(Node* &head, int k) {
    Node* IatFirst = new Node(k);

    // basic condition for linked list 
    if(head == NULL) {
        head = IatFirst;
    }else {
        IatFirst->next = head;
        head = IatFirst;
    }

}

// insert at node end of linked list
void InsertAtEnd(Node* &head, int k) {
    Node* Iatend = new Node(k);
    if(head == NULL) {
        head = Iatend;
    }else {
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = Iatend;
    }
    
}


// insert node at middle 
void InAtMiddle(Node* head, int k) {
    // basic condition
    Node* NodeToInsert = new Node(k);
    if(head == nullptr) {
        head = NodeToInsert;
        return;
    }

    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if(prev == NULL) {
        // This means there's only one element in the list so insert after the first element
        NodeToInsert->next = head->next;
        head->next = NodeToInsert;
    } else {
        NodeToInsert->next = slow;
        prev->next = NodeToInsert;
    }

/*    
    while (fast->next != NULL)
    {
        fast = fast->next;
        if(fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    if(prev != NULL) {
        cout<<"Middle data "<<slow->data<<endl;
        // NodeToInsert->next = slow->next;
        // slow->next = NodeToInsert;
        NodeToInsert->next = slow;
        prev->next = NodeToInsert;
    } else {
        cout << "No Middle element"<<endl;
    }
*/
}

// insert node at any postion of linkedlist

void InsertAtPos(Node* &head, int pos, int k) {

    if(pos == 1) {
        InsertAtFirst(head, k);
    } else {

        
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        cout<<"Total Node before inserting the node  = "<< cnt << endl;

        Node* NodeToIns = new Node(k);
        Node* temp1 = head;
        int num = 1;
        while(num < pos - 1) {
            temp1 = temp1->next;
            num++;
        }

        if(temp1->next == NULL) {
            temp1->next = NodeToIns;
        } else {
            NodeToIns->next = temp1->next;
            temp1->next = NodeToIns;
        }    
    }
}






void Print(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    cout << "Linked_operation.cpp" << endl;
    
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Node* head = n1;
    Print(head);

    cout<<"Inserting node at first"<<endl;
    InsertAtFirst(head, 0);
    Print(head);
    
    cout<<"Inserting node at End"<<endl;
    InsertAtEnd(head, 9);
    Print(head);

    cout<<"Inserting node at Middle"<<endl;
    InAtMiddle(head, 7);
    Print(head);

    int pos;
    cout<<"Enter pos value"<<endl;
    cin>>pos;
    cout<<"Inserting node at pos = "<< pos << endl;
    
    InsertAtPos(head, pos, 44);
    Print(head);

    return 0;
} 