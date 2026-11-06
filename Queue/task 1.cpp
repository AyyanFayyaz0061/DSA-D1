#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int size;
    int count;
    int f;
    int r;

public:
    myQueue(int s) {
        size = s;
        arr = new T[size];
        count = 0;
        f = 0;
        r = -1;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        r = (r + 1) % size;
        arr[r] = value;
        count++;
        cout << "Element added successfully!" << endl;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }

        T value = arr[f];
        f = (f + 1) % size;
        count--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }

        return arr[f];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << arr[(f + i) % size] << " ";
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    myQueue<int> q(5);
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Front";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            cout << "Removed: " << q.deQueue() << endl;
            break;

        case 3:
            cout << "Front: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}