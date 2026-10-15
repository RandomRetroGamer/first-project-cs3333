#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) { 
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            //cout << "Queue is empty\n";
            return -1;
        }
        Node* temp = front;
        int removedData = temp->data;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;

        return removedData;
    }

	int peek() { 
        if (isEmpty()) {
            //cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* current = front;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); 

    cout << "Dequeued: " << q.dequeue() << endl; 
    q.display(); 

    cout << "Front element: " << q.peek() << endl; 

    cout << "Dequeued: " << q.dequeue() << endl; 
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display(); 

    cout << "Dequeued: " << q.dequeue() << endl; 
    q.display(); 

    return 0;
}
