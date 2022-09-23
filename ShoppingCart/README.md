The following is the README given to me by the instructor.

# Online shopping cart
## Problem Description  
This program extends the earlier "Online shopping cart" program. Please copy ItemToPurchase.c and ItemToPurchase.h into the ShoppingCart folder.  

<br />
1. Updates to ItemToPurchase.c and ItemToPurchase.h

- Extend the ItemToPurchase struct to contain a new data member called itemDescription. It should hold a maximum of 80 characters, including the '\0' terminator.   

```
char itemDescription[] 
```
- Extend the MakeItemBlank() function in ItemToPurchase.c so that it sets the itemDescription member to "none"

- Add a function declaration for PrintItemDescription() to ItemToPurchase.h and implement it in ItemToPurchase.c. This function takes an ItemToPurchase struct as a parameter and outputs the itemName and itemDescription as shown in the output below:
   - itemName: Bottled Water
   - itemDescription: Deer Park, 12 oz.

<br />
Ex. of PrintItemDescription() output:

```
Bottled Water: Deer Park, 12 oz.
```
<br />
2. Define each of the functions declared in the ShoppingCart.h header file by implementing them in ShoppingCart.c

The ShoppingCart struct as well as function declarations for the related functions described below have been provided in ShoppingCart.h. Details regarding each function as well as expected return values are included in the comments associated with each function declaration in ShoppingCart.h.  Please study those comments carefully before beginning implementation.  

**DO NOT MODIFY THE PROVIDED ShoppingCart.h HEADER FILE**

**Hint:** Some functions can initially be function stubs (empty functions), to be completed 
in later steps. 

The following is a summary of ShoppingCart.h header  
- ShoppingCart Structure
   - char customerName [ ]
   - char currentDate [ ]
   - ItemToPurchase cartItems [ ] - has a maximum of 10 slots (can hold up to 10 items of any quantity)
   - int cartSize - the number of filled slots in array cartItems [ ] (number of items in cart of any quantity)

- ShoppingCart Functions
   - AddItem()
   - RemoveItem()
   - GetNumItemsInCart() 
   - GetCostOfCart() 
   - PrintInvoice()

```
John Doe's Shopping Cart - February 1, 2016
Number of Items: 8

Nike Romaleos 2 @ $189 = $378
Chocolate Chips 5 @ $3 = $15
Powerbeats 2 Headphones 1 @ $128 = $128

Total: $521
```
   - PrintDescriptions()

```
John Doe's Shopping Cart - February 1, 2016

Item Descriptions
Nike Romaleos: Volt color, Weightlifting shoes
Chocolate Chips: Semi-sweet
Powerbeats Headphones: Bluetooth headphones
```
<br />
3. In main(), prompt the user for a customer's name and today's date. Output the name and date. Create an object of type ShoppingCart. 
<br /><br />

```
Enter Customer's Name:
John Doe
Enter Today's Date:
February 1, 2016

Customer Name: John Doe
Today's Date: February 1, 2016
```
<br />
4. Implement the program menu in the provided main.c source file.  You may implement this directly in main() or by creating a PrintMenu() function that takes a ShoppingCart as a parameter. Each option is represented by a single character as shown in the example output below. If the an invalid character is entered, continue to prompt for a valid choice. Continue to execute the menu until the user enters q to Quit.  

*Hint: Implement Quit before implementing other options.*

```
PROGRAM MENU
a - Add item to cart
r - Remove item from cart
i - Output item descriptions
o - Output shopping cart
q - Quit

Choose an option:
```
<br />
5. Implement "Add item to cart" menu option. 
<br /><br />

```
ADD ITEM TO CART
Enter the item name:
Nike Romaleos
Enter the item description:
Volt color, Weightlifting shoes
Enter the item price:
189
Enter the item quantity:
2
```

<br />
6. Implement the "Output shopping cart" menu option.
<br /><br />

```
John Doe's Shopping Cart - February 1, 2016
Number of Items: 8

Nike Romaleos 2 @ $189 = $378
Chocolate Chips 5 @ $3 = $15
Powerbeats Headphones 1 @ $128 = $128

Total: $521
```
<br />
7. Implement the "Output item descriptions" menu option. 
<br /><br />

```
John Doe's Shopping Cart - February 1, 2016

Item Descriptions
Nike Romaleos: Volt color, Weightlifting shoes
Chocolate Chips: Semi-sweet
Powerbeats Headphones: Bluetooth headphones
```

<br />
8. Implement the "Remove item from cart" menu option. 
<br /><br />

```
Enter name of item to remove:
Chocolate Chips
```
<br />
