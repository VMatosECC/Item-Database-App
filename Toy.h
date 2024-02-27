#pragma once
#include "Item.h"


class Toy : public Item {
private:
    //Data members
    string manufacturer;
    string ageRange;

public:
    //Muatators and Accessors ----------------------------------------------------
    void   setManufacturer(string Manufacturer) { this->manufacturer = manufacturer; }
    void   setageRange(string ageRange) { this->ageRange = ageRange; }

    string getManufacturer() { return manufacturer; }
    string getAgeRange() { return ageRange; }

    //Constructors ---------------------------------------------------------------
    Toy(string id, string name, double price, string supplier,
        string Manufacturer, string ageRange)
        : Item(id, name, price, supplier) {
        setManufacturer(Manufacturer);
        setageRange(ageRange);
    }

    //User-Defined Functions ----------------------------------------------------
    string toString()
    {
        stringstream sout;
        sout << this 
            << " Toy [" << Item::toString() 
            << ", Manufacturer: " << manufacturer
            << ", ageRange: " << ageRange << "]";
        return sout.str();
    }
};

