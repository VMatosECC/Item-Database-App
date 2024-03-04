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
    string  id;             // unique identifier (letter + 4 digits)
    string  name;           // name of the item
    double  price;          // price in USA dollars  
    string* supplier;       // pointer to a string object.

    static int count;       //tally the number of Items created so far.

    //Utility functions
    string titleCase(string str) {
        //Convert the first character of each word to uppercase and the rest to lowercase.
        // Skip over multiple spaces. Example: "the   quick BROWN fox" -> "The Quick Brown Fox"
        char previous = ' ';
        char curr = ' ';
        string result = "";

        for (int i = 0; i < str.length(); i++) {
            curr = str[i];                  //current character

            if (curr == ' ' && previous == ' ') {
                continue;                   //Skip over multiple spaces.
            }

            if (previous == ' ') {          //begining of a word
                result += toupper(curr);
            }
            else {
                result += tolower(curr);
            }
            previous = curr;
        }
        //Remove trailing whitespace
        if(curr == ' '){
            result.pop_back();
        }
        return result;
    }

    //Validate ID (first character must be a letter, followed by 4 digits)
    bool isValidId(string id) {
        if (id.length() != 5) {
            return false;
        }
        if (!isalpha(id[0])) {
            return false;
        }
        for (int i = 1; i < 5; i++) {
            if (!isdigit(id[i])) {
                return false;
            }
        }
        return true;
    }
        
public:
    //Mutators
    void setId(string id) {
        //TODO: Add validation. First character must be a letter, followed by 4 digits.
        //TODO: If ID is X1000 (none provided), add (static) counter value to last digits,
        //      e.g. X1001 for first item, X1002 for second, etc.
        if (!isValidId(id)) {
            throw invalid_argument("Invalid ID: " + id);    //much better option!
        }
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
        //RED FLAG: This is a shallow copy (it should be avoided).
        //You may want to change it to a deep copy!!!
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
    Item(string id = "X1000", string name = "NA", double price = 0, string supplier = "NA") {
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
        //----------------------------------------------

        //cout << "+++ Item " << this->getId() << " destroyed." << endl;
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

    //// Copy-Constructors Version 2 (assumes operator= already overloaded) =============
    //// BEST PRACTICE
    //Item(const Item& sourceItem) {
    //    *this = sourceItem;
    //    count++;
    //}

    //User-Defined Functions ----------------------------------------------
    // By adding virtual modifier the class becomes polymorphic
    virtual string toString() {
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

    friend void showItem(Item& i);

    friend void showItem(Item& i) {
        cout << " Friend ==> " << i.getId() << ", " << i.getName() << endl;
    }

};

//Initialize the static data member ------------------------------------
int Item::count = 0;

//End of the class definition ------------------------------------------