
#include <iostream>
#include <list>
using namespace std;

struct Node{
    int data;
    Node *next;
    
    Node(int d){ 
        data = d;
        next = nullptr;
    }
};

class LinkedList{
    private: Node* head;
    
    public:
    LinkedList(): head(nullptr){}
    // Function to append a new node at the end
    void Append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    //Insert a node at the front of a linked list
    void InsertNodeToHead(int val){
        Node *newNode = new Node{val};
        newNode->next = head;
        head = newNode;
    }
    
    //Insert a node after a given node with the value "key".
    void InsertNode(int key, int val){
        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }

        if(!temp){
            cout << "Node with value " << key << " not found!" << endl;
            return; 
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    //Insert a node at the end of a linked list
    void InsertNodeToTail(int val){
        Node *newNode = new Node{val};
        
        if (!head) { //The list is empty
            cout << "The list is empty." << endl;
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }
    
    void DeleteNode(int d){
        Node *temp = head;
        if (!head) {
            cout << "Node with value " << d << " not found!" << endl;
            return;
        }

        if (head->data == d) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        while (temp->next && temp->next->data != d) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node with value " << d << " not found!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
    
     // Function to display the linked list
    void Display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
    LinkedList emptyList;
    emptyList.InsertNodeToTail(10);
    cout << "The linked list after inserting 10 to the tail: ";
    emptyList.Display();

    emptyList.InsertNodeToTail(20);
    cout << "The linked list after inserting 20 to the tail: ";
    emptyList.Display();
    cout << "" << endl;

    int listArray[] = {1, 3, 5, 7, 9};
    
    Node *head = nullptr;
    
    LinkedList lkList;
    
    for(int i = 0; i < sizeof(listArray)/sizeof(listArray[0]); i++)
    {
        lkList.Append(listArray[i]);
    }
    
    cout<<"The created linked List: ";
    lkList.Display();
	cout << "" << endl;
    
    lkList.InsertNodeToHead(0);
    cout<<"The linked list after adding 0: ";
    lkList.Display();
    cout << "" << endl;

    lkList.InsertNode(5, 6);
    cout<<"The linked list after adding 6: ";
    lkList.Display();
    cout << "" << endl;

	lkList.DeleteNode(0);
    cout << "The linked list after deleting 0: ";
    lkList.Display();
    cout << "" << endl;

    lkList.DeleteNode(10);
    cout << "The linked list after deleting 10: ";
    lkList.Display();
    cout << "" << endl;

    lkList.DeleteNode(7);
    cout << "The linked list after deleting 7: ";
    lkList.Display();

    return 0;
}