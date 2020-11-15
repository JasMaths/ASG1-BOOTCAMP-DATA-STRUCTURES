#include <stdio.h>
#include "Menu_Dessert_Drink.cpp"

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

int main()
{
    int input;
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
            break;
        case 5:
            return 0;
            break;
        }
    } while (input < 1 || input > 5);

    return 0;
}