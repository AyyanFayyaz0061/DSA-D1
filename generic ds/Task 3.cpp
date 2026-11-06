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

        this->arr[this->currentSize++] = value;
    }

    Type removeElementFromEnd() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return Type();
        }

        return this->arr[--this->currentSize];
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
        if (full() || index < 0 || index > this->currentSize)
            return false;

        for (int i = this->currentSize; i > index; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[index] = value;
        this->currentSize++;

        return true;
    }

    Type last() {
        if (empty())
            return Type();

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value) {
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] == value)
                return true;
        }

        return false;
    }

    void display() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < this->currentSize; i++)
            cout << this->arr[i] << " ";

        cout << endl;
    }
};

template <typename Type>
class CustomList : public MyList<Type> {
public:
    CustomList(int m = 10, int c = 0) : MyList<Type>(m, c) {}

    CustomList(const CustomList& obj) : MyList<Type>(obj) {}

    bool isPrime(Type n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    Type sum_ofPrime() {
        Type sum = 0;

        for (int i = 0; i < this->currentSize; i++) {
            if (isPrime(this->arr[i]))
                sum += this->arr[i];
        }

        return sum;
    }

    Type secondMaxEven() {
        Type max1 = 0, max2 = 0;
        bool first = false, second = false;

        for (int i = 0; i < this->currentSize; i++) {
            Type x = this->arr[i];

            if (x % 2 == 0) {
                if (!first || x > max1) {
                    if (first && x != max1) {
                        max2 = max1;
                        second = true;
                    }

                    max1 = x;
                    first = true;
                }
                else if (x < max1 && (!second || x > max2)) {
                    max2 = x;
                    second = true;
                }
            }
        }

        if (!second) {
            cout << "Second maximum even number not found!" << endl;
            return Type();
        }

        return max2;
    }

    Type secondMinOdd() {
        Type min1 = 0, min2 = 0;
        bool first = false, second = false;

        for (int i = 0; i < this->currentSize; i++) {
            Type x = this->arr[i];

            if (x % 2 != 0) {
                if (!first || x < min1) {
                    if (first && x != min1) {
                        min2 = min1;
                        second = true;
                    }

                    min1 = x;
                    first = true;
                }
                else if (x > min1 && (!second || x < min2)) {
                    min2 = x;
                    second = true;
                }
            }
        }

        if (!second) {
            cout << "Second minimum odd number not found!" << endl;
            return Type();
        }

        return min2;
    }

    void printDuplicates() {
        bool found = false;

        for (int i = 0; i < this->currentSize; i++) {
            bool alreadyPrinted = false;

            for (int j = 0; j < i; j++) {
                if (this->arr[i] == this->arr[j]) {
                    alreadyPrinted = true;
                    break;
                }
            }

            if (alreadyPrinted)
                continue;

            for (int j = i + 1; j < this->currentSize; j++) {
                if (this->arr[i] == this->arr[j]) {
                    cout << this->arr[i] << " ";
                    found = true;
                    break;
                }
            }
        }

        if (!found)
            cout << "No duplicates found!";

        cout << endl;
    }

    void rotateClockwaise(int r) {
        int n = this->currentSize;
        int mid = n / 2;

        if (n == 0)
            return;

        r = r % (n - mid);
        if (r < 0)
            r += (n - mid);

        for (int i = 0; i < r; i++) {
            Type last = this->arr[n - 1];

            for (int j = n - 1; j > mid; j--)
                this->arr[j] = this->arr[j - 1];

            this->arr[mid] = last;
        }

        r = r % (mid);
        if (mid > 0) {
            for (int i = 0; i < r; i++) {
                Type last = this->arr[mid - 1];

                for (int j = mid - 1; j > 0; j--)
                    this->arr[j] = this->arr[j - 1];

                this->arr[0] = last;
            }
        }
    }

    void rotateanitclockwaise(int rt) {
        int n = this->currentSize;
        int mid = n / 2;

        if (n == 0)
            return;

        if (mid > 0) {
            rt = rt % mid;
            if (rt < 0)
                rt += mid;

            for (int i = 0; i < rt; i++) {
                Type first = this->arr[0];

                for (int j = 0; j < mid - 1; j++)
                    this->arr[j] = this->arr[j + 1];

                this->arr[mid - 1] = first;
            }
        }

        int secondSize = n - mid;

        rt = rt % secondSize;
        if (rt < 0)
            rt += secondSize;

        for (int i = 0; i < rt; i++) {
            Type first = this->arr[mid];

            for (int j = mid; j < n - 1; j++)
                this->arr[j] = this->arr[j + 1];

            this->arr[n - 1] = first;
        }
    }
};

int main() {
    CustomList<int> obj(20);
    int choice, value, index, r;

    do {
        cout << "\n1. Add at First";
        cout << "\n2. Add at Last";
        cout << "\n3. Remove from End";
        cout << "\n4. Remove from Start";
        cout << "\n5. Insert At Index";
        cout << "\n6. Search Element";
        cout << "\n7. Display List";
        cout << "\n8. Sum of Prime Numbers";
        cout << "\n9. Second Maximum Even";
        cout << "\n10. Second Minimum Odd";
        cout << "\n11. Print Duplicates";
        cout << "\n12. Clockwise Rotation";
        cout << "\n13. Anti-Clockwise Rotation";
        cout << "\n14. Exit";

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
                cout << "Inserted successfully!" << endl;
            else
                cout << "Invalid index or list full!" << endl;
            break;

        case 6:
            cout << "Enter value: ";
            cin >> value;

            if (obj.search(value))
                cout << "Element found!" << endl;
            else
                cout << "Element not found!" << endl;
            break;

        case 7:
            obj.display();
            break;

        case 8:
            cout << "Prime Sum: " << obj.sum_ofPrime() << endl;
            break;

        case 9:
            cout << "Second Maximum Even: " << obj.secondMaxEven() << endl;
            break;

        case 10:
            cout << "Second Minimum Odd: " << obj.secondMinOdd() << endl;
            break;

        case 11:
            obj.printDuplicates();
            break;

        case 12:
            cout << "Enter rotations: ";
            cin >> r;
            obj.rotateClockwaise(r);
            obj.display();
            break;

        case 13:
            cout << "Enter rotations: ";
            cin >> r;
            obj.rotateanitclockwaise(r);
            obj.display();
            break;

        case 14:
            cout << "Program ended!";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 14);

    return 0;
}