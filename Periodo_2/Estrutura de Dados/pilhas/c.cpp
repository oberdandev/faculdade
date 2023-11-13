
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // maximum size of the stack

class Stack {     
private:
    int top; // index of the top element in the stack
    int arr[MAX_SIZE]; // array to store the elements of the stack
public:
    Stack() { // constructor to initialize the stack
        top = -1; // set top to -1 to indicate an empty stack
    }
    bool isEmpty() { // method to check if the stack is empty
        return top == -1;
    }
    bool isFull() { // method to check if the stack is full
        return top == MAX_SIZE - 1;
    }
    void push(int x) { // method to push an element onto the stack
        if (isFull()) { // check if the stack is full
            cout << "Error: Stack overflow" << endl;
            return;
        }
        arr[++top] = x; // increment top and add the element to the stack
    }
    int pop() { // method to pop an element from the stack
        if (isEmpty()) { // check if the stack is empty
            cout << "Error: Stack underflow" << endl;
            return -1;
        }
        return arr[top--]; // return the top element and decrement top
    }
    int peek() { // method to return the top element of the stack
        if (isEmpty()) { // check if the stack is empty
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return arr[top]; // return the top element
    }
};

int main() {
    Stack s; // create a new stack
    s.push(1); // push some elements onto the stack
    s.push(2);
    s.push(3);
    cout << s.pop() << endl; // pop an element from the stack and print it
    cout << s.peek() << endl; // print the top element of the stack
    cout << s.pop() << endl; // pop another element from the stack and print it
    return 0;
}

