struct NodeOrders *addOrders(struct NodeFood *temp2)
{
    time_t current;
    time(&current);
    struct NodeOrders *temp = (NodeOrders *)malloc(sizeof(NodeOrders));
    strcpy(temp->Orders.Food.name, temp2->Food.name);
    strcpy(temp->Orders.Food.type, temp2->Food.type);
    strcpy(temp->Orders.Food.topping, temp2->Food.topping);
    strcpy(temp->Orders.Food.flavor, temp2->Food.flavor);
    strcpy(temp->Orders.orderedtime, ctime(&current));
    temp->Orders.Food.price = temp2->Food.price;
    temp->Orders.Food.calories = temp2->Food.calories;
    temp->Orders.Food.size = temp2->Food.size;
    temp->Orders.temptime = temp2->Food.cookingTime;
    temp->Orders.cp = 1;
    temp->next = temp->prev = NULL;

    return temp;
};

void orderFood()
{
    if (n == 1)
    {
        puts("There is no dessert or drink on the list!");
        printf("\nPress ENTER to continue");
        getchar();
        return;
    }
    else
    {
        printTable();
        addOrder();
    }
}

void pushNodeOrder(struct NodeOrders *temp)
{
    if (!head2)
    {
        head2 = tail2 = temp;
    }
    else
    {
        tail2->next = temp;
        temp->prev = tail2;
        tail2 = temp;
    }
}

void createOrder(int order)
{
    curr = head;
    int i = 1;
    while (i != order)
    {
        i++;
        curr = curr->next;
    }
    pushNodeOrder(addOrders(curr));
}

void addOrder()
{
    int order;
    printf("Choose a menu to order [%d - %d]: ", 1, n - 1);
    scanf("%d", &order);
    puts("Successfully added to order list!");
    orderCtr++;

    createOrder(order);
    getchar();
    getchar();
    main_menu();
}

void printTable()
{
    system("cls || clear");
    printf("| %-3s | %-20s | %-6s | %-10s | %-10s | %-10s | %-5s |\n", "No", "Name", "Price", "Topping", "Calories", "Flavor", "Size");
    puts("--------------------------------------------------------------------------------------");

    curr = head;
    int i = 1;
    while (curr)
    {
        if(curr->Food.calories==0)
        printf("| %-3d | %-20s | %-6d | %-10s | %-10s | %-10s | %-5c |\n", i, curr->Food.name, curr->Food.price, curr->Food.topping, "-", curr->Food.flavor, curr->Food.size);
        else
        printf("| %-3d | %-20s | %-6d | %-10s | %-10.2lf | %-10s | %-5c |\n", i, curr->Food.name, curr->Food.price, curr->Food.topping, curr->Food.calories, curr->Food.flavor, curr->Food.size);
        curr = curr->next;
        i++;
    }
}