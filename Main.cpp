#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000
#include "Variables_prototypes.cpp"
#include "Menu_Dessert_Drink.cpp"
#include "orderFood.cpp"

void welcome()
{
    puts("Welcome to Opercooked");
    printf("Today profit : $ %d\n", 0);
    puts("===========================");
    puts("1. Add Dessert or Beverage");
    puts("2. View Cooking Process");
    puts("3. View Order History");
    puts("4. Order Dessert or Beverage");
    puts("5. Exit");
}

int main_menu_input()
{
    int option;
    scanf("%d", &option);
    return option;
}

void main_menu()
{
    int input;
    system("cls || clear");
    welcome();
    do
    {
        printf(">> ");
        input = main_menu_input();
        switch (input)
        {
        case 1:
            addFood();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            orderFood();
            break;
        case 5:
            return;
            break;
        }
    } while (input < 1 || input > 5);
}

int main()
{
    main_menu();
    return 0;
}
