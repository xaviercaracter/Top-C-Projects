/*
 * Author: Xavier Caracter
 * Date: Fri 15 Oct 2021 11:57:48 PM MDT
 * Description: Lab 8 ItemToPurchase .c file
 */
#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

int MakeItemBlank(ItemToPurchase * itemPtr){
    if(itemPtr == NULL){
        return -1;
    }

    strcpy(itemPtr->itemName, "none");
    itemPtr->itemPrice = 0;
    itemPtr -> itemQuantity = 0;
    strcpy(itemPtr -> itemDescription, "none");

    return 0;
}

void PrintItemCost(ItemToPurchase item){
       printf("%s %d @ $%d = $%d\n", 
                item.itemName, 
                item.itemQuantity, 
                item.itemPrice, 
                (item.itemQuantity * item.itemPrice)); 

    }

void PrintItemDescription(ItemToPurchase item){
    printf("%s: %s\n", item.itemName, item.itemDescription);
}