/*
 * Author: Xavier Caracter
 * Date: Fri 15 Oct 2021 11:57:48 PM MDT
 * Description: Lab 8 Shopping Cart .c file
 */
#include<stdio.h>
#include<string.h>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart){
    ShoppingCart currCart = cart;
    if(cart.cartSize >= 10){
        printf("Item not added: Shopping Cart is full.\n");
        return currCart;
    }
    currCart.cartItems[currCart.cartSize] = item;
    currCart.cartSize++;
    return currCart;
}

ShoppingCart RemoveItem(char name[], ShoppingCart cart){
    int found_idx = 0;
    int idx = 0;
    int isFound = 0;
    int currCartSize = cart.cartSize;

    if(cart.cartSize <= 0){
        printf("Cart is empty, cannot remove.\n");
        return cart;
    }

    while(found_idx < currCartSize){
        if(strcmp(name, cart.cartItems[found_idx].itemName) == 0){
            isFound = 1;
            break;
        }
        found_idx++;
    }

    if(isFound == 0){
        printf("Item not found in cart, nothing removed.\n");
    } else {
        for(idx = found_idx; idx < cart.cartSize-1; idx++){
            cart.cartItems[idx] = cart.cartItems[idx + 1];
        }
        cart.cartSize--;
    }
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart){
    int totalNumItems = 0;
    int currCartSize = cart.cartSize;
    int i = 0;
    for(i = 0; i < currCartSize; i++){
        totalNumItems += cart.cartItems[i].itemQuantity;
    }

    return totalNumItems;
}

int GetCostOfCart(ShoppingCart cart){
    int totalCostCart = 0;
    int currCartSize = cart.cartSize;
    int i = 0;
    for(i = 0; i < currCartSize; i++){
        totalCostCart += (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
    }

    return totalCostCart;
}


void PrintInvoice(ShoppingCart cart){
    int currCartSize = cart.cartSize;
    int i = 0;

    printf("\n%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n", GetNumItemsInCart(cart));
    printf("\n");

    for(i = 0; i < currCartSize; i++){
        PrintItemCost(cart.cartItems[i]);
    }

    printf("\nTotal: $%d\n", GetCostOfCart(cart));

}

void PrintDescriptions(ShoppingCart cart){
    int currCartSize = cart.cartSize;
    int i = 0;

    printf("\n%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n\n");

    for(i = 0; i < currCartSize; i++){
        PrintItemDescription(cart.cartItems[i]);
    }

}