void orderFood()
{
    if (n == 1)
    {
        puts("There is no dessert or drink on the list!");
        printf("\nPress ENTER to continue ");
        getchar();
        return;
    }
    else
    {
        printTable();
        addOrder();
    }
}

void addOrder()
{
    char type1[10] = "Dessert", type2[10] = "Drink";
    printf("Choose a menu to order [%d - %d]: ", 1, n - 1);
    scanf("%d", &order);
    puts("Successfully added to order list!");
    orderCtr++;

    // Time
    time_t current;
    time(&current);

    // Struct
    strcpy(Orders[orderCtr].type, Food[order].type);
    strcpy(Orders[orderCtr].name, Food[order].name);
    strcpy(Orders[orderCtr].topping, Food[order].topping);
    strcpy(Orders[orderCtr].flavor, Food[order].flavor);
    strcpy(Orders[orderCtr].orderedtime, ctime(&current));
    Orders[orderCtr].size = Food[order].size;
    Orders[orderCtr].price = Food[order].price;
    Orders[orderCtr].cookingTime = Food[order].cookingTime;

    FILE *fp = fopen("orderHistory.txt", "w");

    for (int i = 1; i <= orderCtr; i++)
    {
        fprintf(fp, "%d %s %d %s %.2lf %s %c %s", i, Orders[i].name, Orders[i].price, (strcmp(Orders[i].type, type1) != 0) ? "-" : Orders[i].topping, Orders[i].calories, (strcmp(Orders[i].type, type1) == 0) ? "-" : Orders[i].flavor, (Orders[i].size != 'S' && Orders[i].size != 'M' && Orders[i].size != 'L') ? '-' : Orders[i].size, Orders[i].orderedtime);
    }

    fclose(fp);

    sleep();
    main_menu();
}

void printTable()
{
    system("cls || clear");
    char type1[10] = "Dessert", type2[10] = "Drink";

    printf("| %-3s | %-20s | %-6s | %-10s | %-10s | %-10s | %-5s |\n", "No", "Name", "Price", "Topping", "Calories", "Flavor", "Size");
    puts("--------------------------------------------------------------------------------------");
    for (int i = 1; i <= n - 1; i++)
    {
        if (strcmp(Food[i].type, type1) == 0)
        {
            printf("| %-3d | %-20s | %-6d | %-10s | %-10.2lf | %-10s | %-5c |\n", i, Food[i].name, Food[i].price, (strcmp(Food[i].type, type1) != 0) ? "-" : Food[i].topping, Food[i].calories, (strcmp(Food[i].type, type1) == 0) ? "-" : Food[i].flavor, (Food[i].size != 'S' && Food[i].size != 'M' && Food[i].size != 'L') ? '-' : Food[i].size);
        }
        else
        {
            printf("| %-3d | %-20s | %-6d | %-10s | %-10s | %-10s | %-5c |\n", i, Food[i].name, Food[i].price, (strcmp(Food[i].type, type1) != 0) ? "-" : Food[i].topping, "-", (strcmp(Food[i].type, type1) == 0) ? "-" : Food[i].flavor, (Food[i].size != 'S' && Food[i].size != 'M' && Food[i].size != 'L') ? '-' : Food[i].size);
        }
    }
}