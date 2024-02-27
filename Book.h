#pragma once
#include "Item.h"


class Book : public Item {
private:
    //Data members
    string author;
    int    pages;

public:
    //Muatators and Accessors ----------------------------------------------------
    void   setAuthor(string author) { this->author = author; }
    void   setPages(int pages) { this->pages = pages; }

    string getAuthor() { return author; }
    int    getPages()  { return pages; }

    //Constructors ---------------------------------------------------------------
    Book(string id, string name, double price, string supplier,
        string author, int pages)
        : Item(id, name, price, supplier) {
        setAuthor(author);
        setPages(pages);
    }

    //User-Defined Functions ----------------------------------------------------
    string toString()  
    {
        stringstream sout;
        sout << this 
            << " Book [" << Item::toString() 
            << ", Author: " << author 
            << ", Pages: " << pages << "]";
        return sout.str();
    }
};

