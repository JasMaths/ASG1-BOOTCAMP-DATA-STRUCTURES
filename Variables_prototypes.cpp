
struct food
{
	char type[10], name[100], topping[100], flavor[100], size;
	int price, cookingTime;
	double calories;
};

struct orders
{
	struct food Food;
    char orderedtime[100];
};

struct NodeFood
{
	struct food Food;
	NodeFood *next, *prev;
}*head, *tail, *curr;

struct NodeOrders
{
	struct orders Orders;
	NodeOrders *next, *prev;
}*head2, *tail2, *curr2;


int n = 1,a = 0,profit = 0;       //TOTAL DESSERTS & DRINKS  (Start from 1)
int orderCtr = 0, id = 0;

int strcmpInsensitive(char *topping), cookingTimeDessert(int time), cookingTimeDrink(char flavor[]); //Prototypes
void dessertMenu(), drinkMenu(), sleep(), main_menu();
char *defstring(char *str);
void printTable(), addOrder(), write(); // orderFood's Prototypes
