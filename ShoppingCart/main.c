/*
 * Author: Xavier Caracter
 * Date: Fri 15 Oct 2021 11:57:48 PM MDT
 * Description: Lab 8 Activity Driver file
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

/*
 * BufferPurge: Remove all remaining characters
 *    from input buffer.
 */
void BufferPurge(void)
{
   char c = getchar();
   while (c != '\n' && c != EOF)
   {
      c = getchar();
   }
}

/* 
 * Prints menu for the program 
 */

void PrintMenu(ShoppingCart cart)
{
   char menuOption;
   ItemToPurchase item;
   char nameOfRemovedItem[80];

   do
   {
      printf("MENU\n");
      printf("a - Add item to cart\n");
      printf("r - Remove item from cart\n");
      printf("i - Output item descriptions\n");
      printf("o - Output shopping cart\n");
      printf("q - Quit\n");

      printf("\nChoose an option: ");
      scanf(" %c", &menuOption);
      switch (menuOption)
      {

      case 'a':
         /* Adds an item to the hopping cart */
         BufferPurge();
         printf("ADD ITEM TO CART\n");
         printf("Enter the item name:\n");
         scanf("%79[^\n]s", item.itemName);
         BufferPurge();
         printf("Enter the item description:\n");
         scanf("%79[^\n]s", item.itemDescription);
         BufferPurge();
         printf("Enter the item price:\n");
         while(scanf("%d", &item.itemPrice) < 1){
            printf("Please enter an integer value\n");
            BufferPurge();
         }
         BufferPurge();
         printf("Enter the item quantity:\n");
         while(scanf("%d", &item.itemQuantity) < 1){
            printf("Please enter an integer value.");
            BufferPurge();
         }
         BufferPurge();

         cart = AddItem(item, cart);
         printf("\n");
         break;
      case 'r':
         /* Remove an item form the shopping cart */
         BufferPurge();
         printf("Enter name of item to remove:\n");
         scanf("%70[^\n]s", nameOfRemovedItem);
         BufferPurge();
         cart = RemoveItem(nameOfRemovedItem, cart);
         printf("\n");
         break;
      case 'i':
         /* Print the item decriptions */
         BufferPurge();
         PrintDescriptions(cart);
         printf("\n");
         break;
      case 'o':
         /* Print the invoice of the shopping cart */
         BufferPurge();
         PrintInvoice(cart);
         printf("\n");
         break;
      case 'q':
         /* Quits the program and says goodbye */
         printf("\nGoodbye!\n");
         break;
      default:
         printf("\nError: Unknown option selected\n");
         break;
      }
   } while (menuOption != 'q');
}

int main(void)
{
   /* Initialize the shopping cart */
   ShoppingCart cart;

   /* Get the customer informaiton */
   printf("Enter Customer's Name: ");
   fgets(cart.customerName, 70, stdin);
   cart.customerName[strlen(cart.customerName) - 1] = '\0';

   printf("Enter Today's Date: ");
   fgets(cart.currentDate, 70, stdin);
   cart.customerName[strlen(cart.customerName) - 1] = '\0';

   /* Setting inital cart size to 0 */
   cart.cartSize = 0;
   printf("\n");

   /* Prints the menu and allows for operations to occur */
   PrintMenu(cart);

   return 0;
}