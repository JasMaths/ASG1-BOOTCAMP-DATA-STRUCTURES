void view_order_history()
{

    if (orderCtr == 0)
    {
        printf("There is no order history\n");
        printf("Press Enter to continue");
        getchar();
        return;
    }
    else
    {
        printf("| %-3s | %-20s | %-6s | %-10s | %-10s | %-10s | %-5s | %-20s |\n", "No", "Name", "Price", "Topping", "Calories", "Flavor", "Size", "Order Time");
        puts("-------------------------------------------------------------------------------------------------------------");
        for (int i = 1; i <= orderCtr; i++)
        {
            if (strcmp(Orders[i].type, "Dessert") == 0)
            {
                printf("| %-3d | %-20s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %-30s |\n", i, Orders[i].name, Orders[i].price, (strcmp(Orders[i].type, "Dessert") != 0) ? "-" : Orders[i].topping, Orders[i].calories, (strcmp(Orders[i].type, "Dessert") == 0) ? "-" : Orders[i].flavor, (Orders[i].size != 'S' && Orders[i].size != 'M' && Orders[i].size != 'L') ? '-' : Orders[i].size, Orders[i].orderedtime);
            }
            else
            {
                printf("| %-3d | %-20s | %-6d | %-10s | %-10s | %-10s | %-5c | %-30s |", i, Orders[i].name, Orders[i].price, (strcmp(Orders[i].type, "Dessert") != 0) ? "-" : Orders[i].topping, "-", (strcmp(Orders[i].type, "Dessert") == 0) ? "-" : Orders[i].flavor, (Orders[i].size != 'S' && Orders[i].size != 'M' && Orders[i].size != 'L') ? '-' : Orders[i].size, Orders[i].orderedtime);
            }
        }
        sleep();
        main_menu();
    }
}
