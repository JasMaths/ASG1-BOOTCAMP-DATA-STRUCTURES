
#include<stdio.h>
#include<conio.h>
int main()
{
 
 printf (" | %-3s | %-9s | %3s | %3s | %3s | %-9s |%5s|%9s|\n\n", "No", "Name", "Price", "Topping", "Callories", "Flavor", "Size", "Order Time");
 printf (" | %-3s | %-9s | %-5s | %-7s | %-9s | %-9s |%-5s|%7s|\n", "1", "Mojito", "15", "-", "-", "Mint", "M", "2020/04/25 11:17:33 AM");
 printf (" | %-3s | %-9s | %-5s | %-7s | %-9s | %-9s |%-5s|%9s|\n", "2", "Mojito", "15", "-", "-", "Mint", "M", "2020/04/25 11:17:37 AM");
 printf (" | %-3s | %3s | %-5s | %-7s | %-9s | %-9s |%-5s|%9s|\n", "3", "Coca Cola", "10", "-", "-", "Mix Berry", "S", "2020/04/25 11:17:39 AM");
 printf (" | %-3s | %3s | %-5s | %-7s | %-9s | %-9s |%-5s|%9s|\n", "4", "Lime Ball", "20", "Honey", "15.50", "-", "-", "2020/04/25 11:17:29 AM");
 printf (" | %-3s | %3s | %-5s | %3s | %-9s | %-9s |%-5s|%9s|\n", "5", "ChocoLava", "20", "Caramel", "2.50", "-", "-", "2020/04/25 11:17:42 AM");
 printf (" | %-3s | %3s | %-5s | %-7s | %-9s | %-9s |%-5s|%9s|\n", "6", "Lime Ball", "20", "Honey", "15.50", "-", "-", "2020/04/25 11:17:56 AM");

printf("\n");
printf("Press Enter to continue");
 getch();
 
}