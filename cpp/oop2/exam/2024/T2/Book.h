#include <bits/stdc++.h>
#pragma once
using namespace std;
template <class T>
class Book {
    public:
        string BookName;
        string Author;
        T Pages;
        Book(string BookName_, string Author_, T Page_) : BookName(BookName_), Author(Author_), Pages(Page_){}
        void show() {
            cout << "Book name: " << BookName << ", " << "Author: " << Author << ", Pages: " << Pages << '\n';
        }
        bool operator< (const Book<T>& other) {
            return this->Pages < other.Pages;
        }
};