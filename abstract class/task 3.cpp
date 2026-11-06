#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
public:
    virtual void display() = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book() {
        title = "";
        author = "";
        pages = 0;
    }

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    int getPages() {
        return pages;
    }

    string getTitle() {
        return title;
    }

    void display() {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {
        name = "";
        date = "";
        edition = "";
    }

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getEdition() {
        return edition;
    }

    string getName() {
        return name;
    }

    void display() {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

class Library {
private:
    Book books[100];
    Newspaper newspapers[100];

    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book b) {
        if (bookCount < 100) {
            books[bookCount] = b;
            bookCount++;
        }
    }

    void addNewspaper(Newspaper n) {
        if (newspaperCount < 100) {
            newspapers[newspaperCount] = n;
            newspaperCount++;
        }
    }

    void displayCollection() {
        cout << "\nBooks Collection:\n";

        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "\nNewspapers Collection:\n";

        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - i - 1; j++) {
                if (newspapers[j].getEdition() >
                    newspapers[j + 1].getEdition()) {

                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }

        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getName() == name) {
                return &newspapers[i];
            }
        }

        return nullptr;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook != nullptr) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper != nullptr) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}