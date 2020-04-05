#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    char *str;
    struct Node *next;
};

void    print_node(struct Node *n)
{
    while (n!= NULL)
    {
        printf("%d\n", n->value);
        printf("%s\n", n->str);
        n = n->next;
    }
}

int     main(void)
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->value = 1;
    head->str = "cRYP70N"; 
    head->next = second;
  
    second->value = 2;
    second->str = "Otmane";
    second->next = third; 
  
    third->value = 3;
    third->str = "kimdil";
    third->next = NULL; 
  
    print_node(head); 
}