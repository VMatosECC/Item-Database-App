// Item-Database-App.cpp 

#include <vector>
#include "Item.h"
#include "Book.h"
#include "toy.h"

//Prototypes----------------------------------------
void experiment01();
void experiment02();


int main()
{
   //experiment01();
   experiment02();


    cout << "\nAll done!\n";
}

//---------------------------------------------------------------------------------------
void experiment02() {
    Book b1("B1111", "The Berenstain Bears", 9.99, "Random House", "Stan & Jan B", 100);
    cout << "\nb1 " << b1.toString() << endl;
    Book b2("B2222", "The Cat in the Hat", 12.99, "Penguin", "Dr. Seuss", 50);
    cout << "\nb2 " << b2.toString() << endl;

    Toy t1("T3333", "Lego", 19.99, "COSTCO", "Lego Intl", "5+");
    cout << "\nt1 " << t1.toString() << endl;
    Toy t2("T4444", "Barbie", 29.99, "Walmart", "Mattel", "3+");
    cout << "\nt2 " << t2.toString() << endl;

    cout << "\nCount of Items: " << Item::getCount() << endl << endl;
    
    //--------------------------------------------------------------------------------
    //CAUTION. The following code will work only if Item is declared polymorphic!
    //         It is polymorphic if it has at least one virtual function.
    //         The toString function should be made virtual in the Item class.
    //         You MUST use references Item*  
    //--------------------------------------------------------------------------------
    cout << "\nTesting the DATABASE vector<Items>" << endl;
    vector<Item*> db {&b1, &b2, &t1, &t2};
    for (Item* i : db) {
        cout << i->toString() << endl;
    }


}
//----------------------------------------------------------------------------------------
void experiment01() {
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


    // TRY-1. Before adding a copy constructor 
    // shallow copy of i2 to i3. The clone and the source 
    // point to the same memory location (BAD!)
    // --------------------------------------------------
    Item i3 = i2;

    //TRY-2. After adding a copy constructor
    // deep copy of i2 to i3. The clone and the source 
    // point to different memory locations (GOOD!)
    // --------------------------------------------------
    // Item i3(i2);   

    //TRY-3A. The above copy-constructor must be modified
    //TRY-3B  to handle the deep copy of i2 to i3
    // //--------------------------------------------------
    //Item i3;          //TRY-3A. 
    //i3 = i2;          //TRY-3B  



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
}