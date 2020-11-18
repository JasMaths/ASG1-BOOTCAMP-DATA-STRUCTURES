
int temptimer[1000],av[1000]={0};

void TableHeading()
{
	printf("| %-3s | %-8s | %-20s | %-6s | Time Left |\n", "No", "Type" ,"Name", "Price");
        puts("--------------------------------------------------------------");
}

void NoProcess()
{
	printf("There is no cooking process recently!\n");
	printf("\n");
	printf("Press Enter to continue\n");
	sleep();
	main_menu();
}

void ViewProcess()
{	
	if(a==0)
	{
		for(int i = 1;i <= orderCtr;i++)
		{
			temptimer[i] = Orders[i].cookingTime;
		}
		a++;
	}
	else
	{
		for(int i = 1;i<=orderCtr;i++)
		{
			temptimer[i]-=10;
		}
	}
	int ctr = 0;
	for(int i = 1;i<=orderCtr;i++)
	{
		if(temptimer[i]>0)
		{
			ctr = 1;
		}
	}
	
	if(ctr==0)
	{
		NoProcess();
	}
	else
	{
		TableHeading();
		for(int i = 1;i<=orderCtr;i++)
		{
			if(temptimer[i]>0)
			{
				printf("| %-3d | %-8s | %-20s | %-6d | %-8ds |\n", i, Orders[i].type, Orders[i].name, Orders[i].price, temptimer[i]);
			}
			else
			{
				ctr--;
				av[i]++;
			}
		}
		for(int i = 1;i<=orderCtr;i++)
		{
			if(av[i]==1)
			{
				profit += Orders[i].price;
				av[i]++;
			}	
		}
	}	
	sleep();
	main_menu();
}

void CheckProcess()
{
	system("cls || clear");
	if(orderCtr==0)
		NoProcess();
	else
		ViewProcess();
}

