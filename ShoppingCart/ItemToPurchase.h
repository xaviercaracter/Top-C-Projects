/*
 * Author: Xavier Caracter
 * Date: Fri 15 Oct 2021 11:57:48 PM MDT
 * Description: Lab 8 ItemToPurchase .h file
 */
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#define MAX_ITEM_NAME_SIZE 80
#define MAX_DECRIPTION_SIZE 80

/* Define itemtopurche struct */
struct itemtopurchase {
    char itemName[MAX_ITEM_NAME_SIZE];
    int itemPrice;
    int itemQuantity;
    //New field added itemDesctiption
    char itemDescription[MAX_DECRIPTION_SIZE];
};

/* Define ItemToPurchase type */
typedef struct itemtopurchase ItemToPurchase;

/* MakeItemBlank: initialize the fields in the 
 * specified ItemToPurchase struct
 * item - Pointer to ItemToPurchase object
 * return - 0 on success, -1 on error
 */
int MakeItemBlank(ItemToPurchase * itemPtr);

/* 
 * PrintItemCost: Display item cost 
 *  by printing to stdout.
 * item - ItemToPurchase object to be displayed
 */
void PrintItemCost(ItemToPurchase item);

/* 
 * PrintItemDescription: Display item description 
 *  by printing to stdout.
 * item - ItemToPurchase object to be displayed
 */
void PrintItemDescription(ItemToPurchase item);




#endif