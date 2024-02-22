// Item-Database-App.cpp 
#include <iostream>
#include "Item.h"


int main()
{
    Item i1;
    cout << "i1 " << i1.toString() << endl;
    i1.setId("A1234");
    i1.setName(" GREEN  apples");
    i1.setPrice(2.99);
    cout << "i1 " << i1.toString() << endl;

    cout << "Count of Items: " << Item::getCount() << endl;

    Item i2("B5678", "   red     apples", 3.99, "Chiquita Corp");
    cout << "i2 " << i2.toString() << endl;

    cout << "\nCount of Items: " << Item::getCount() << endl;
    cout << "Count of Items: " << i2.getCount() << endl;

    //Before adding a copy constructor   
     Item i3 = i2;  //TRY-1
    
    // Item i3(i2);   //TRY-2

    //Item i3;          //TRY-3A
    //i3 = i2;          //TRY-3B

    cout << "\nBEFORE i2 " << i2.toString() << endl;
    cout << "BEFORE i3 " << i3.toString() << endl;

    i3.setSupplier("Orchard Hills");

    cout << "AFTER  i3 " << i3.toString() << endl;
    cout << "AFTER  i2 " << i2.toString() << endl;

    //Testing overloaded << operator
    cout << "\nOVERLOADED << i1: " << i1 << endl;
    cout << "OVERLOADED << i2: " << i2 << endl;
    cout << "OVERLOADED << i3: " << i3 << endl;

    cout << "\nAll done!\n";
}

