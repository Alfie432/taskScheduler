#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    char task[48];
    int id;
    int priority;
    struct Node *next;
} Ticket;


// prototypes
int generateID(void);
void clearBuffer(void);


int main(void)
{
    int choice;

    while (1)
    {
        printf("\nEnter choice:");
        scanf("%d", &choice);
        clearBuffer();
    }

    return 0; 
}


int generateID(void)
{
    int min = 100;
    int max = 999;

    srand(time(NULL));
    int number = (rand() % (max - min + 1)) + min; 

    return number;
}


void clearBuffer(void)
{
    int ch = getchar();

    while ((ch != EOF) && (ch != '\n'))
    {
        ch = getchar();
    }
}