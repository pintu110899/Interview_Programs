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



int main() {
    cout << "Linked_operation.cpp" << endl;
    return 0;
}