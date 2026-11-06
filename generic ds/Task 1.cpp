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

int main() {
    cout << "Abstract List Class Created Successfully!" << endl;

    return 0;
}