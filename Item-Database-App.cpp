// Item-Database-App.cpp 
#include <iostream>
#include "Item.h"


int main()
{
    //Testing the Item class. Zero-arguments constructor
    Item i1;
    cout << "i1 " << i1.toString() << endl;
    i1.setId("A1234");
    i1.setName(" GREEN  apples   ");
    i1.setPrice(-2.99);
    //case corrected, leading/trailing spaces removed, price set to 0.0
    cout << "i1 " << i1.toString() << endl;     

    //Testing the Static member function getCount
    cout << "Count of Items: " << Item::getCount() << endl;

    //Testing the Item class. ALL-arguments constructor
    Item i2("B5678", "   red     apples", 3.99, "Chiquita CORP");
    cout << "i2 " << i2.toString() << endl;

    //calling static member function getCount using object and class name
    cout << "\nCount of Items: " << Item::getCount() << endl;
    cout << "Count of Items: " << i2.getCount() << endl;

      
     Item i3 = i2;  // TRY-1. Before adding a copy constructor 
                    // shallow copy of i2 to i3. The clone and the source 
                    // point to the same memory location (BAD!)
                    // --------------------------------------------------
                    
    // Item i3(i2);   //TRY-2. After adding a copy constructor
                    // deep copy of i2 to i3. The clone and the source 
                    // point to different memory locations (GOOD!)
                    // --------------------------------------------------

    //Item i3;          //TRY-3A. New copy constructor must be modified
    //i3 = i2;          //TRY-3B  to handle the deep copy of i2 to i3
                        //--------------------------------------------------


    //Common code for testing the three scenarios set for the copy constructor 
    cout << "\nBEFORE - i2 " << i2.toString() << endl;
    cout << "BEFORE - i3 " << i3.toString() << endl;

    i3.setSupplier("Orchard Hills");    //The clone changes supplier
                                        //Does it affect the source?

    cout << "AFTER - i3 " << i3.toString() << endl;
    cout << "AFTER - i2 " << i2.toString() << endl;

    //Testing overloaded << operator ---------------------------------------
    cout << "\nOVERLOADED << i1: " << i1 << endl;
    cout << "OVERLOADED << i2: " << i2 << endl;
    cout << "OVERLOADED << i3: " << i3 << endl;

    cout << "\nAll done!\n";
}

