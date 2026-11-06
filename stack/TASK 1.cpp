#include <iostream>
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
        cout << "Element pushed successfully!" << endl;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return arr[current--];
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return arr[current];
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
    myStack<int> s(5);
    int choice, value;

    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Top";
        cout << "\n4. Check Empty";
        cout << "\n5. Check Full";
        cout << "\n6. Display";
        cout << "\n7. Exit";
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
            cout << "Top element: " << s.top() << endl;
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
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 7);

    return 0;
}