void TableHeading()
{
	printf("| %-3s | %-8s | %-20s | %-6s | Time Left |\n", "No", "Type" ,"Name", "Price");
        puts("--------------------------------------------------------------");
}

void CountProfit()
{
	curr2 = head2;
	while (curr2)
    {
        if(curr2->Orders.temptime <= 0 && curr2->Orders.cp == 1)
		{
			profit+= curr2->Orders.Food.price;
			curr2->Orders.cp = 0;
			cookingCtr++;
		}
		curr2 = curr2->next;
    }
	getchar();
	getchar();
	main_menu();
}

void NoProcess()
{
	printf("There is no cooking process recently!\n");
	printf("\n");
	printf("Press Enter to continue\n");
	CountProfit();
}

void ViewProcessTable()
{	
	TableHeading();
	curr2 = head2;
    int i = 1;
    while (curr2)
    {
		if(curr2->Orders.cp == 1)
		{
			printf("| %-3d | %-8s | %-20s | %-6d | %-8ds |\n", i, curr2->Orders.Food.type, curr2->Orders.Food.name, curr2->Orders.Food.price, curr2->Orders.temptime);
			i++;
			curr2->Orders.temptime -= 10;
		}
        curr2 = curr2->next;
    }
	printf("Press Enter to return to main menu\n");
	CountProfit();
}

void ViewProcess()
{
	system("cls || clear");
	curr2 = head2;
	ctlist = 0;
    while (curr2)
    {
        if(curr2->Orders.temptime > 0 && curr2->Orders.cp == 1)
		{
			ctlist++;
		}
		curr2 = curr2->next;
    }
	if(ctlist > 0)
		ViewProcessTable();
	else
		NoProcess();
}
