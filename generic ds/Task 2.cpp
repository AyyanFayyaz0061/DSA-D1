#include <iostream>
using namespace std;

template <typename Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int m = 10, int c = 0) {
        maxSize = m;
        currentSize = c;
        arr = new Type[maxSize];
    }

    List(const List& obj) {
        maxSize = obj.maxSize;
        currentSize = obj.currentSize;
        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++) {
            arr[i] = obj.arr[i];
        }
    }

    virtual void addElementAtFirstIndex(Type value) = 0;
    virtual void addElementAtLastIndex(Type value) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List() {
        delete[] arr;
    }
};

template <typename Type>
class MyList : public List<Type> {
public:
    MyList(int m = 10, int c = 0) : List<Type>(m, c) {}

    MyList(const MyList& obj) : List<Type>(obj) {}

    bool empty() {
        return this->currentSize == 0;
    }

    bool full() {
        return this->currentSize == this->maxSize;
    }

    int size() {
        return this->currentSize;
    }

    void addElementAtFirstIndex(Type value) {
        if (full()) {
            cout << "List is full!" << endl;
            return;
        }

        for (int i = this->currentSize; i > 0; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type value) {
        if (full()) {
            cout << "List is full!" << endl;
            return;
        }

        this->arr[this->currentSize] = value;
        this->currentSize++;
    }

    Type removeElementFromEnd() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return Type();
        }

        Type value = this->arr[this->currentSize - 1];
        this->currentSize--;

        return value;
    }

    void removeElementFromStart() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < this->currentSize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->currentSize--;
    }

    bool insertAt(int index, Type value) {
        if (full() || index < 0 || index > this->currentSize) {
            return false;
        }

        for (int i = this->currentSize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[index] = value;
        this->currentSize++;

        return true;
    }

    Type last() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return Type();
        }

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value) {
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] == value) {
                return true;
            }
        }

        return false;
    }

    void display() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < this->currentSize; i++) {
            cout << this->arr[i] << " ";
        }

        cout << endl;
    }

    ~MyList() {}
};

int main() {
    MyList<int> obj(10);
    int choice, value, index;

    do {
        cout << "\n1. Add at First";
        cout << "\n2. Add at Last";
        cout << "\n3. Remove from End";
        cout << "\n4. Remove from Start";
        cout << "\n5. Insert At Index";
        cout << "\n6. Show Last Element";
        cout << "\n7. Search Element";
        cout << "\n8. Check Empty";
        cout << "\n9. Check Full";
        cout << "\n10. Show Size";
        cout << "\n11. Display List";
        cout << "\n12. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            obj.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            obj.addElementAtLastIndex(value);
            break;

        case 3:
            cout << "Removed: " << obj.removeElementFromEnd() << endl;
            break;

        case 4:
            obj.removeElementFromStart();
            cout << "First element removed!" << endl;
            break;

        case 5:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;

            if (obj.insertAt(index, value))
                cout << "Element inserted!" << endl;
            else
                cout << "Invalid index or list full!" << endl;
            break;

        case 6:
            cout << "Last element: " << obj.last() << endl;
            break;

        case 7:
            cout << "Enter value: ";
            cin >> value;

            if (obj.search(value))
                cout << "Element found!" << endl;
            else
                cout << "Element not found!" << endl;
            break;

        case 8:
            cout << (obj.empty() ? "List is empty" : "List is not empty") << endl;
            break;

        case 9:
            cout << (obj.full() ? "List is full" : "List is not full") << endl;
            break;

        case 10:
            cout << "Current size: " << obj.size() << endl;
            break;

        case 11:
            obj.display();
            break;

        case 12:
            cout << "Program ended!";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 12);

    return 0;
}