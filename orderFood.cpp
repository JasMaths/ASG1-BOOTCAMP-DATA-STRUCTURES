struct NodeOrders *addOrders(struct NodeFood *curr)
{
    time_t current;
    time(&current);
    struct NodeOrders *temp = (NodeOrders *)malloc(sizeof(NodeOrders));
    strcpy(temp->Orders.Food.name, curr->Food.name);
    strcpy(temp->Orders.Food.type, curr->Food.type);
    strcpy(temp->Orders.Food.topping, curr->Food.topping);
    strcpy(temp->Orders.Food.flavor, curr->Food.flavor);
    strcpy(temp->Orders.orderedtime, ctime(&current));
    temp->Orders.Food.price = curr->Food.price;
    temp->Orders.Food.calories = curr->Food.calories;
    temp->Orders.Food.size = curr->Food.size;
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
    printf("Choose a menu to order [%d - %d]:", 1, n - 1);
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
        printf("| %-3d | %-20s | %-6d | %-10s | %-10.2lf | %-10s | %-5c |\n", i, curr->Food.name, curr->Food.price, curr->Food.topping, curr->Food.calories, curr->Food.flavor, curr->Food.size);
        curr = curr->next;
        i++;
    }
}