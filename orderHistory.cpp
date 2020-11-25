void view_order_history()
{
    if (cookingCtr == 0)
    {
        system("cls || clear");
        printf("There is no order history\n");
        printf("\nPress Enter to continue\n");
        getchar();
        getchar();
        main_menu();
    }
    else
    {
        system("cls || clear");
        printf("| %-3s | %-20s | %-6s | %-10s | %-10s | %-10s | %-5s | %-22s |\n", "No", "Name", "Price", "Topping", "Calories", "Flavor", "Size", "Order Time");
        puts("---------------------------------------------------------------------------------------------------------------");
        curr2 = head2;
        int i = 1;
        while (curr2)
        {
            if(curr2->Orders.cp == 0)
            {
                printf("| %-3d | %-20s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i, curr2->Orders.Food.name, curr2->Orders.Food.price, curr2->Orders.Food.topping, curr2->Orders.Food.calories, curr2->Orders.Food.flavor, curr2->Orders.Food.size, curr2->Orders.year, curr2->Orders.month, curr2->Orders.day, curr2->Orders.hour, curr2->Orders.minute, curr2->Orders.second, curr2->Orders.m);
                curr2 = curr2->next;
                i++;
            }
        }
        printf("\nPress Enter to continue\n");
        getchar();
        getchar();
        main_menu();
    }
}
