#pragma once
#include <iostream>

using namespace std;

enum status {borrowed = 0, onTheBookShelf = 1};
const string statusMsg[] = {"borrowed", "avalaible"}; 

class Book{
private:
    string author;
    string category;
    unsigned int pages;
public:
    status currentStatus;
    Book();
    Book(string setAuthor, string setCategory, unsigned int setPages, status setStatus);
    friend ostream& operator<<(ostream& o, const Book& book);
};

Book::Book(){
    author = "N/A";
    category = "N/A";
    pages = 0;
    currentStatus = borrowed;
}

Book::Book(string setAuthor, string setCategory, unsigned int setPages, status setStatus){
    author = setAuthor;
    category = setCategory;
    pages = setPages;
    currentStatus = setStatus;
}

ostream& operator<<(ostream& o, const Book& book){
    o << book.author << " ";
    o << book.category << " ";
    o << book.pages << " ";
    o << statusMsg[book.currentStatus];
    return o;
}

