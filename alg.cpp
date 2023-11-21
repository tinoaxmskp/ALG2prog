#include <iostream>
#include <string>
#include <list>

class Book {
private:
    std::string title;
    std::list<std::string> authorList;
    int editionYear;
    int bookNumber;
    static int bookCount; // static field to count the number of books

public:
    // Default constructor
    Book(std::string title = "", int editionYear = 0) {
        this->title = title;
        this->editionYear = editionYear;
        bookCount++; // increment the book count
        bookNumber = bookCount; // set the book number to the next free value
    }

    // Copy constructor
    Book(const Book& other) {
        title = other.title;
        authorList = other.authorList;
        editionYear = other.editionYear;
        bookCount++; // increment the book count
        bookNumber = bookCount; // set the book number to the next free value
    }

    // Assignment operator
    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            authorList = other.authorList;
            editionYear = other.editionYear;
        }
        return *this;
    }

    // Getter and setter methods
    std::string getTitle() const {
        return title;
    }

    void setTitle(const std::string& title) {
        this->title = title;
    }

    int getYear() const {
        return editionYear;
    }

    void setYear(int year) {
        editionYear = year;
    }

    int getNumber() const {
        return bookNumber;
    }

    // Method to add an author
    void addAuthor(const std::string& author) {
        authorList.push_back(author);
    }

    // Method to remove an author
    void removeAuthor(const std::string& author) {
        authorList.remove(author);
    }

    // Static method to count the number of books
    static int count() {
        return bookCount;
    }

    // Overloading the shift operator (<<) for printing the book's data
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Book Number: " << book.bookNumber << std::endl;
        os << "Title: " << book.title << std::endl;
        os << "Author List: ";
        for (const std::string& author : book.authorList) {
            os << author << ", ";
        }
        os << std::endl;
        os << "Edition Year: " << book.editionYear << std::endl;
        return os;
    }
};

int Book::bookCount = 0; // initializing the static bookCount field

int main() {
    // Creating instances of the Book class and testing its capabilities
    Book book1("Title 1", 2020);
    book1.addAuthor("Author 1");
    book1.addAuthor("Author 2");

    std::cout << book1;

    Book book2 = book1; // Testing copy constructor
    book2.setTitle("Title 2");
    book2.setYear(2021);
    book2.addAuthor("Author 3");

    std::cout << book2;

    Book book3;
    book3 = book2; // Testing assignment operator
    book3.setTitle("Title 3");
    book3.setYear(2022);
    book3.removeAuthor("Author 1");

    std::cout << book3;

    std::cout << "Number of books created: " << Book::count() << std::endl;

    return 0;
}
