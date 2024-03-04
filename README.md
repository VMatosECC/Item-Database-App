The Item class consists of ID, NAME, PRICE, and a pointer to a SUPPLIER name.
The example illustrates the style used in CS1 and CS2 courses to make a class.
The example explores the effect of shallow vs. deep copying and the use of static data/functions.
Two versions of a copy-constructor are discussed.
Versions of the operator= and operator<< are provided.

Possible Subclasses Derived from Item (ID, name, price).
 
**ElectronicItem**: Inherits from Item class, with additional attributes such as brand, power_consumption, warranty_period, etc.

**ClothingItem**: Inherits from Item, with additional attributes such as size, color, material, style, etc.

**FoodItem**: Inherits from Item, with additional attributes such as expiration_date, calories, nutritional_information, etc.

**BookItem**: Inherits from Item, with additional attributes such as author, genre, publication_date, etc.

**FurnitureItem**: Inherits from Item, with additional attributes such as material, dimensions, weight_capacity, etc.

**ToyItem**: Inherits from Item, with additional attributes such as recommended_age, material, safety_information, etc.

**ToolItem**: Inherits from Item, with additional attributes such as type_of_tool, power_source, intended_use, etc.

**JewelryItem**: Inherits from Item, with additional attributes such as material, gemstone, size, design, etc.

**SportingGoodsItem**: Inherits from Item, with additional attributes such as sport_type, size, material, intended_use, etc.

**AutomotiveItem**: Inherits from Item, with additional attributes such as make, model, year, mileage, engine_type, etc.
