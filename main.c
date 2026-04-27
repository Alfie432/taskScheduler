#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 48

typedef struct Node {
    char task[MAX];
    int id;
    int priority;
    struct Node *next;
} Ticket;


// prototypes
int generateID(void);
void clearBuffer(void);
void addTicket(Ticket *head);
void viewTickets(Ticket *head);


int main(void)
{
    int choice;
    Ticket *head = NULL;

    while (1)
    {
        printf("\n1) Add Ticket\n2) View Tickets\n3) Remove Ticket\n4) End Program\nEnter choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice)
        {
        case 1:
            addTicket(head);
            break;
        case 2:
            viewTickets(head);
            break;
        case 3:
            break;
        case 4:
            // ! make sure to free everything (deleteList())
            free(head);
            return 0; 
            break;
        default:
            continue;
        }
        

        
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


void addTicket(Ticket *head)
{
    // create the first ticket when the linked list is empty
    if (head == NULL)
    {
        head = malloc(sizeof(Ticket));
    }

    Ticket *temp = head;

    // go to the last node, then create an additional node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = malloc(sizeof(Ticket));

    // get info for the ticket
    char enteredTask[MAX];
    int enteredPriority;

    printf("\nEnter Ticket: ");
    fgets(enteredTask, MAX, stdin);

    printf("\nEnter priority (1: Basic, 2: Medium, 3: Important, 4: Crucial) ");
    scanf("%d", &enteredPriority);
    clearBuffer();

    // check if user entered a valid priority ranking, default is 1
    if ((1 <= enteredPriority) && (enteredPriority <= 4))
    {
        temp->priority = enteredPriority;
    }
    else
    {
        temp->priority = 1;
    }

    *temp->task = *enteredTask;
    temp->id = generateID();


    free(temp);
    return;
}


void viewTickets(Ticket *head)
{
    Ticket *temp = head;

    while (temp->next != NULL)
    {
        printf("\nTicket: %s\n", temp->task);
        printf("\nTicket ID: %d\n", temp->id);
        printf("\nTicket Priority: %d\n", temp->priority);
        printf("\n\n"); // for spacing
    }

    free(temp);
    return;
}