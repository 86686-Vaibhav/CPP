#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = 5) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop" << endl;
            return;
        }
        top--;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack(3);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.push(40);

    cout << "Stack contents: ";
    stack.print();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    cout << "Stack after pop: ";
    stack.print();

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}





