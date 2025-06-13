#include "Book.h"
template <class T>
class Library {
    public:
        vector<Book<T>> books;
        Library() {}
        void addBook(const Book<T>& book) {
            books.push_back(book);
        }
        void show() {
            for(int i = 0; i < books.size(); i++) {
                books[i].show();
            }
        }
        void borrowBook(const std::string& title) {
            for(int i = 0; i < books.size(); i++) {
                if(books[i].BookName == title) {
                    cout << "Books Checked out " << title << "." << '\n';
                    return;
                }
            }
            cout << "Book " << title <<" does not exist." << '\n';
        }
};