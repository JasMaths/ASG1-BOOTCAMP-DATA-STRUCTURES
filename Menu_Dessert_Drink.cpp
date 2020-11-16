
void createDessert(char *name, int price, char *topping, double calories, int time, int n)
{
	strcpy(Food[n].type, "Dessert");
	strcpy(Food[n].name, name);
	strcpy(Food[n].topping, topping);
	Food[n].price = price;
	Food[n].calories = calories;
	Food[n].cookingTime = time;
	FILE *fp = fopen("menu.txt", "w"); //FILE
	fprintf(fp, "%d %s %d %s %lf - -\n", n, Food[n].name, Food[n].price, Food[n].topping, Food[n].calories);
	fclose(fp);
}

void createDrink(char *name, int price, char *flavor, char size, int time, int n)
{
	strcpy(Food[n].type, "Drink");
	strcpy(Food[n].name, name);
	strcpy(Food[n].flavor, flavor);
	Food[n].price = price;
	Food[n].size = size;
	Food[n].cookingTime = time;
	FILE *fp = fopen("menu.txt", "w"); //FILE
	fprintf(fp, "%d %s %d - - %s %c\n", n, Food[n].name, Food[n].price, Food[n].flavor, Food[n].size);
	fclose(fp);
}

void addFood()
{
	int input;
	system("cls");
	puts("What do you want to add?");
	puts("1. Dessert");
	puts("2. Drink");
	do
	{
	printf("Choose: ");
	scanf("%d", &input);	
	switch(input)
	{
		case 1:
		dessertMenu();
		break;
		case 2:
                drinkMenu();
		}
	} while (input != 1 && input != 2);
}

void dessertMenu()
{
	char nameTemp[100], toppingTemp[100];
	int priceTemp, extraTime, timeTemp;
	double caloriesTemp;
	
	do
	{
	printf("Input the name [at least 5 characters]: ");
	getchar();
        scanf("%[^\n]", nameTemp);
        }while(strlen(nameTemp) < 5);
    
        do
	{
        printf("Input the price [10 - 500]: $ ");
        scanf("%d", &priceTemp);
	}while(priceTemp < 10 || priceTemp > 500);
    
	do
	{
	printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
	getchar();
	scanf("%[^\n]", toppingTemp);
	extraTime = strcmpInsensitive(toppingTemp);
	}while(extraTime == -1);
	strcpy(toppingTemp, defstring(toppingTemp));
	
	do
	{
	printf("Insert calories [1.00 - 99.00]: ");
	scanf("%lf", &caloriesTemp);
	}while(caloriesTemp < 1.00 || caloriesTemp > 99.00);
	
	timeTemp = cookingTimeDessert(extraTime);
	createDessert(nameTemp, priceTemp, toppingTemp, caloriesTemp, timeTemp, n);
	printf("\nSuccessfully added a new menu!");
	n++;
	sleep(); //Sleep function
	main_menu();
}

void drinkMenu()
{
	char nameTemp[100], flavorTemp[100], sizeTemp;
	int priceTemp, extraTime, timeTemp;
	
	do
	{
	printf("Input the name [at least 5 characters]: ");
	getchar();
	scanf("%[^\n]", nameTemp);
	}while(strlen(nameTemp) < 5);
	
	do
	{
	printf("Input the price [10 - 500]: $ ");
	scanf("%d", &priceTemp);
	}while(priceTemp < 10 || priceTemp > 500);
	
	do
	{
	printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
	getchar();
	scanf("%[^\n]", flavorTemp);
	}while(strcmp(flavorTemp, "Mint") != 0 && strcmp(flavorTemp, "Mix Berry") != 0 && strcmp(flavorTemp, "Cheese") != 0);
	
	do
	{
	printf("Input the size [S | M | L](Case Sensitive): ");
	getchar();
	scanf("%c", &sizeTemp);
	}while(sizeTemp != 'S' && sizeTemp != 'M' && sizeTemp != 'L');
	
	timeTemp = cookingTimeDrink(flavorTemp);
	printf("\nSuccessfully added a new menu!");
	createDrink(nameTemp, priceTemp, flavorTemp, sizeTemp, timeTemp, n);
	n++;
	sleep(); //Sleep function
	main_menu();
}

int strcmpInsensitive(char topping[])
{
	for(int i = 0;topping[i] != '\0';i++)
	{
		if(topping[i] >= 'A' && topping[i] <= 'Z')
		{
			topping[i] += 32;
		}
	}
	if(strcmp(topping, "caramel") == 0)
	{
		return 1;
	}
	else if(strcmp(topping, "honey") == 0)
	{
		return 2;
	}
	else if(strcmp(topping, "syrup") == 0)
	{
		return 3;
	}
	else
	{
		return -1;
	}
}
int cookingTimeDessert(int extra)
{
	int time = 0;
	if(extra == 1)
	{
		time += 10;
	}
	else if(extra == 2)
	{
		time += 15;
	}
	else
	{
		time += 20;
	}
	time += (rand() % 41) + 50;
	return time;
}

int cookingTimeDrink(char flavor[])
{
	int time = 0;
	if(strcmp(flavor, "Mint") == 0)
	{
		time += 10;
	}
	else if(strcmp(flavor, "Mix Berry") == 0)
	{
		time += 20;
	}
	else
	{
		time += 30;
	}
	time += (rand() % 41) + 10;
	return time;
}

char *defstring(char str[])
{
	for(int i = 0;str[i] != '\0';i++)
	{
		if(i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
	return str;
}

void sleep()
{
	for(long long int i = 0;i < 1e9;i++);
}

