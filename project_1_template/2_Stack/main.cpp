#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>

using namespace std;

// Stack implementation using a linked list
class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* topNode;  // Pointer to the top of the stack

public:
    Stack() : topNode(nullptr) {}  // Constructor initializes an empty stack

    // Push operation
    void push(int value) {
        Node* newNode = new Node{ value, topNode };
        topNode = newNode;
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cerr << "Stack underflow! Exiting...\n";
            exit(EXIT_FAILURE);
        }
        int value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    // Peek operation (view top element)
    int peek() const {
        if (isEmpty()) {
            cerr << "Stack is empty!\n";
            exit(EXIT_FAILURE);
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};



// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    Stack s;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {  // If token is an operand, push it
            s.push(stoi(token));
        }
        else {  // Otherwise, it's an operator
            int operand2 = s.peek(); s.pop();
            int operand1 = s.peek(); s.pop();

            if (token == "+")
                s.push(operand1 + operand2);
            else if (token == "-")
                s.push(operand1 - operand2);
            else if (token == "*")
                s.push(operand1 * operand2);
            else if (token == "/")
                s.push(operand1 / operand2);
			else if (token == "^")
                s.push(static_cast<int>(pow(operand1, operand2)));
        }
    }
    return s.peek();  // The final result is at the top of the stack
}

int main() {
    string postfixExpression1 = "1 2 3 * +";  // Equivalent to: 1 + (2 * 3)
    cout << "Result: " << evaluatePostfix(postfixExpression1) << endl;  // Output: 7

    string postfixExpression2 = "1 2 3 4 ^ * + 5 +";  
    cout << "Result: " << evaluatePostfix(postfixExpression2) << endl; 
    
    string postfixExpression3 = "1 2 * 3 4 ^ + 5 +";
    cout << "Result: " << evaluatePostfix(postfixExpression3) << endl;
    
    return 0;
}
