#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

int strcmpInsensitive(char *topping), cookingTimeDessert(int time), cookingTimeDrink(char flavor[]); //Prototypes
void dessertMenu(), drinkMenu(), sleep();

struct dessert
{
	char nameDessert[100], toppingDessert[100];
	int price, cookingTime;
	double calories;
};

struct drink
{
	char nameDrink[100], flavorDrink[100], size;
	int price, cookingTime;
};

struct dessert Dessert[MAX]; //STRUCT of ARRAY
struct drink Drink[MAX];
int n1 = 0, n2 = 0; //TOTAL DESSERTS & DRINKS

void createDessert(char *name, int price, char *topping, double calories, int time, int n)
{
	strcpy(Dessert[n].nameDessert, name);
	strcpy(Dessert[n].toppingDessert, topping);
	Dessert[n].price = price;
	Dessert[n].calories = calories;
	Dessert[n].cookingTime = time;
}

void createDrink(char *name, int price, char *flavor, char size, int time, int n)
{
	strcpy(Drink[n].nameDrink, name);
	strcpy(Drink[n].flavorDrink, flavor);
	Drink[n].size = size;
	Drink[n].price = price;
	Drink[n].cookingTime = time;
}

void addFood()
{
	int input;
	system("clear");
	printf("\nWhat do you want to add?\n");
	puts("1. Dessert");
	puts("2. Drink");
	puts("3. Return");
	do
	{
		printf("Choose: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			dessertMenu();
			break;
		case 2:
			drinkMenu();

		case 3:
			return;
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
	} while (strlen(nameTemp) < 5);

	do
	{
		printf("Input the price [10 - 500]: $ ");
		scanf("%d", &priceTemp);
	} while (priceTemp < 10 || priceTemp > 500);

	do
	{
		printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
		getchar();
		scanf("%[^\n]", toppingTemp);
		extraTime = strcmpInsensitive(toppingTemp);
	} while (extraTime == -1);

	do
	{
		printf("Insert calories [1.00 - 99.00]: ");
		scanf("%lf", &caloriesTemp);
	} while (caloriesTemp < 1.00 || caloriesTemp > 99.00);

	timeTemp = cookingTimeDessert(extraTime);
	printf("\nSuccessfully added a new menu!");
	createDessert(nameTemp, priceTemp, toppingTemp, caloriesTemp, timeTemp, n1);
	n1++;
	sleep(); //Sleep function
	addFood();
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
	} while (strlen(nameTemp) < 5);

	do
	{
		printf("Input the price [10 - 500]: $ ");
		scanf("%d", &priceTemp);
	} while (priceTemp < 10 || priceTemp > 500);

	do
	{
		printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
		getchar();
		scanf("%[^\n]", flavorTemp);
	} while (strcmp(flavorTemp, "Mint") != 0 && strcmp(flavorTemp, "Mix Berry") != 0 && strcmp(flavorTemp, "Cheese") != 0);

	do
	{
		printf("Input the size [S | M | L](Case Sensitive): ");
		getchar();
		scanf("%c", &sizeTemp);
	} while (sizeTemp != 'S' && sizeTemp != 'M' && sizeTemp != 'L');

	timeTemp = cookingTimeDrink(flavorTemp);
	printf("\nSuccessfully added a new menu!");
	createDrink(nameTemp, priceTemp, flavorTemp, sizeTemp, timeTemp, n2);
	n2++;
	sleep(); //Sleep function
	addFood();
}
int strcmpInsensitive(char topping[])
{
	for (int i = 0; topping[i] != '\0'; i++)
	{
		if (topping[i] >= 'A' && topping[i] <= 'Z')
		{
			topping[i] += 32;
		}
	}
	if (strcmp(topping, "caramel") == 0)
	{
		return 1;
	}
	else if (strcmp(topping, "honey") == 0)
	{
		return 2;
	}
	else if (strcmp(topping, "syrup") == 0)
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
	if (extra == 1)
	{
		time += 10;
	}
	else if (extra == 2)
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
	if (strcmp(flavor, "Mint") == 0)
	{
		time += 10;
	}
	else if (strcmp(flavor, "Mix Berry") == 0)
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
void sleep()
{
	for (long long int i = 0; i < 1e9; i++)
		;
}

// int main()
// {
// 	addFood();
// 	return 0;
// }
