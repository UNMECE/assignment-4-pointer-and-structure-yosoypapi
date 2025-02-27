#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"

void add_items(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[])
{
    const int size =5;
    Item *item_list = malloc(size * sizeof(Item));

    add_items(item_list, 5.00,"19282","breakfast","Reese's cereal",0);
    add_items(item_list, 3.95, "79862", "dairy","milk",1);
    add_items(item_list, 2.50, "09123","produce", "apples", 2);
    add_items(item_list, 4.99, "09253", "bakery", "bread", 3);
    add_items(item_list, 15.00, "51006", "meat", "chicken", 4);

    print_items(item_list, size);
    printf("Average price of items = %.6f\n", average_price(item_list,size));

    if(argc ==2)
    {
        char *search_sku = argv[1];
        int found =0;
        for(int i =0;i<size; i++)
        {
            if(strcmp(item_list[i].sku, search_sku)==0)
            {
                printf("Item found:\n");
                printf("Item name = %s\n", item_list[i].name);
                printf("Item sku = %s\n", item_list[i].sku);
                printf("Item category = %s\n", item_list[i].category);
                printf("Item price = %.6f\n", item_list[i].price);
                found =1;
                break;

            }
        }
        if(!found)
        printf("Item not found.\n");
    }
    free_items(item_list, size);
    return 0;
}

void add_items(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    item_list[index].price =price;
    item_list[index].sku =strdup(sku);
    item_list[index].category =strdup(category);
    item_list[index].name = strdup(name);
}

void free_items(Item *item_list, int size)
{
    for(int i=0; i<size;i++)
    {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size)
{
    double total=0;
    for(int i=0;i<size;i++) total += item_list[i].price;
    return total/size;
}

void print_items(Item *item_list, int size)
{
    for(int i =0; i < size; i++)
    {
        printf("######\n");
        printf("Item name = %s\n", item_list[i].name);
        printf("Item sku = %s\n", item_list[i].sku);
        printf("Item category = %s\n", item_list[i].category);
        printf("Item price = %.6f\n", item_list[i].price);
    }
}

