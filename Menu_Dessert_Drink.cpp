
struct NodeFood *createDessert(char *name, int price, char *topping, double calories, int time)
{
   struct NodeFood *temp = (NodeFood*)malloc(sizeof(NodeFood));
   strcpy(temp->Food.type, "Dessert");
   strcpy(temp->Food.name, name);
   strcpy(temp->Food.topping, topping);
   strcpy(temp->Food.flavor, "-");
   temp->Food.size = '-';
   temp->Food.price = price;
   temp->Food.calories = calories;
   temp->Food.cookingTime = time;
   temp->next = temp->prev = NULL;
   return temp;
}

struct NodeFood *createDrink(char *name, int price, char *flavor, char size, int time)
{
   struct NodeFood *temp = (NodeFood*)malloc(sizeof(NodeFood));
   strcpy(temp->Food.type, "Drink");
   strcpy(temp->Food.name, name);
   strcpy(temp->Food.flavor, flavor);
   strcpy(temp->Food.topping, "-");
   temp->Food.size = size;
   temp->Food.price = price;
   temp->Food.calories = 0;
   temp->Food.cookingTime = time;
   temp->next = temp->prev = NULL;
   return temp;
}

void pushNodeFood(struct NodeFood* temp)
{
	if(!head)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
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
		break;
	}
    }while(input != 1 && input != 2);
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
	pushNodeFood(createDessert(nameTemp, priceTemp, toppingTemp, caloriesTemp, timeTemp));
	n++;
	printf("\nSuccessfully added a new menu!\n");
	getchar(); //Makan enter doank (better than sleep function :v)
	getchar();
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
	pushNodeFood(createDrink(nameTemp, priceTemp, flavorTemp, sizeTemp, timeTemp));
	n++;
	printf("\nSuccessfully added a new menu!\n");
	getchar();
	getchar();
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

