#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Item
{
private:
    //Data members
    string  id;       // unique identifier (letter + 4 digits)
    string  name;     // name of the item
    double  price;    // price in USA dollars  
    string* supplier; // pointer to a string object.

    static int count; //tally the number of Items created.

    //Utility functions
    string titleCase(string str) {
        //Converts the first character of each word to uppercase and the rest to lowercase.
        char previous = ' ';
        string result = "";

        for (int i = 0; i < str.length(); i++) {
            char curr = str[i];     //current character

            if (curr == ' ' && previous == ' ') {
                continue;           //Skip over multiple spaces.
            }

            if (previous == ' ') {
                result += toupper(curr);
            }
            else {
                result += tolower(curr);
            }
            previous = curr;
        }
        return result;
    }

public:
    //Mutators
    void setId(string id) {
        //TODO: Add validation. First character must be a letter, followed by 4 digits.
        this->id = id;
    }

    void setName(string name) {
        //Correction. Name must be stored in title case.
        this->name = titleCase(name);
    }

    void setPrice(double price) {
        this->price = abs(price); //Ensure price is positive.
    }

    void setSupplier(string supplier) {
        //GOOD PRACTICE (copy-constructor)
        // create a new string object and assign it to the supplier pointer.
        // this->supplier = new string(titleCase(supplier));
        
        //BAD PRACTICE
        // assign the address of a local variable to the supplier pointer.
        // this->supplier = &supplier;
        *(this->supplier) = titleCase(supplier);

    }

    //Accessors
    string getId() {
        return id;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }

    string getSupplier() {
        return *supplier;
    }

    static int getCount() {
        return count;
    }

   
    //Constructors
    Item(string id = "NA", string name = "NA", double price = 0, string supplier = "NA") {
        setId(id);
        setName(name);
        setPrice(price);

        this->supplier = new string();
        setSupplier(supplier);
        count++;
    }

    //Destructor
    ~Item() {
        // Make sure copy-constructor was implemented well!
        // delete this->supplier;    //avoid memory leaks
        cout << "+++ Item " << this->getId() << " destroyed." << endl;
        count--;
    }

    ////Copy-Constructors Version 1 ===============================================
    //Item(const Item& sourceItem) {
    //    setId(sourceItem.id);
    //    setName(sourceItem.name);
    //    setPrice(sourceItem.price);

    //    this->supplier = new string();
    //    setSupplier(*(sourceItem.supplier));
    //    count++;
    //}

    //// Copy-Constructors Version 2 (assumes operator= already declared) =============
    //// BEST PRACTICE
    //Item(const Item& sourceItem) {
    //    *this = sourceItem;
    //    count++;
    //}

    //User-Defined Functions
    string toString() {
        stringstream sout;
        sout << fixed << setprecision(2);
        sout << this << " Item [ID: " << getId() << ", Name: " << getName()
            << ", Price: " << getPrice() 
            << ", Supplier: " << getSupplier() << "]";
        return sout.str();
    }

    //void operator=(const Item& sourceItem) {
    //    setId(sourceItem.id);
    //    setName(sourceItem.name);
    //    setPrice(sourceItem.price);

    //    this->supplier = new string();
    //    setSupplier(*(sourceItem.supplier));
    //}

    friend ostream& operator<< (ostream& sout, Item& item) {
        sout << item.toString();
        return sout;
    }
};
//Initialize the static data member.
int Item::count = 0;
