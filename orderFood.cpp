int order[1000], orderCtr = 0, id = 0;

void printTable(), addOrder(), write();

void orderFood()
{
    if (n == 1)
    {
        puts("There is no dessert or drink on the list!");
        puts("\nPress ENTER to continue");
        sleep();
        main_menu();
    }
    else
    {
        printTable();
        addOrder();
        // write();
    }
}

// void write()
// {
//     char type1[10] = "Dessert", type2[10] = "Drink";
// }

void addOrder()
{
    char type1[10] = "Dessert", type2[10] = "Drink";
    printf("Choose a menu to order [%d - %d]: ", 1, n - 1);
    scanf("%d", &order[id]);
    puts("Successfully added to order list!");
    id++;
    orderCtr++;

    FILE *fp = fopen("orderHistory.txt", "w");

    for (int i = 0; i < orderCtr; i++)
    {
        fprintf(fp, "%d %s %d %s %.2lf %s %c\n", i + 1, Food[order[i]].name, Food[order[i]].price, (strcmp(Food[order[i]].type, type1) != 0) ? "-" : Food[order[i]].topping, Food[order[i]].calories, (strcmp(Food[order[i]].type, type1) == 0) ? "-" : Food[order[i]].flavor, (Food[order[i]].size != 'S' && Food[order[i]].size != 'M' && Food[order[i]].size != 'L') ? '-' : Food[order[i]].size);
    }

    fclose(fp);
    sleep();
    main_menu();
}

void printTable()
{
    system("cls || clear");
    // if (n == 1)
    // {
    //     puts("There is no dessert or drink on the list!");
    //     puts("\nPress ENTER to continue");
    // }
    // else
    // {
    char type1[10] = "Dessert", type2[10] = "Drink";

    printf("| %-3s | %-20s | %-6s | %-10s | %-10s | %-10s | %-5s |\n", "No", "Name", "Price", "Topping", "Calories", "Flavor", "Size");
    puts("--------------------------------------------------------------------------------------");
    for (int i = 1; i <= n - 1; i++)
    {
        printf("| %-3d | %-20s | %-6d | %-10s | %-10.2lf | %-10s | %-5c |\n", i, Food[i].name, Food[i].price, (strcmp(Food[i].type, type1) != 0) ? "-" : Food[i].topping, Food[i].calories, (strcmp(Food[i].type, type1) == 0) ? "-" : Food[i].flavor, (Food[i].size != 'S' && Food[i].size != 'M' && Food[i].size != 'L') ? '-' : Food[i].size);
    }
    // }
}