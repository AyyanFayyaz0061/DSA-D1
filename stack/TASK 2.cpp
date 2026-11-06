#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int size;
    int current;
    stack<T> minStack;

public:
    myStack(int s) {
        size = s;
        arr = new T[size];
        current = -1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }

        arr[++current] = value;

        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }

        cout << "Element pushed!" << endl;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        T value = arr[current--];

        if (value == minStack.top()) {
            minStack.pop();
        }

        return value;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return arr[current];
    }

    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return minStack.top();
    }

    bool isEmpty() const {
        return current == -1;
    }

    bool isFull() const {
        return current == size - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        for (int i = current; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    ~myStack() {
        delete[] arr;
    }
};

int main() {
    myStack<int> s(10);
    int choice, value;

    do {
        cout << "\n1. Push element";
        cout << "\n2. Pop element";
        cout << "\n3. Show top element";
        cout << "\n4. Check empty";
        cout << "\n5. Check full";
        cout << "\n6. Display stack";
        cout << "\n7. Show minimum element";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Removed: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;

        case 5:
            cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Minimum element: " << s.getMin() << endl;
            break;

        case 8:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 8);

    return 0;
}