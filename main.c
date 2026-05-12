#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 48

typedef struct Node {
    char task[MAX];
    int id;
    int priority;
    struct Node *next;
} Ticket;


// prototypes
int generateID(Ticket *head);
void clearBuffer(void);
void addTicket(Ticket *head);
void viewTickets(Ticket *head);
void deleteList(Ticket *head);


int main(void)
{
    int choice;
    srand(time(NULL));

    Ticket *head = (Ticket *)malloc(sizeof(Ticket)); // type casting makes sure the memory is for a Ticket structure
    // keep the head node empty, its purpose is to only point to the linkedList, not be apart of it
    head->next = NULL;
    head->id = -1;
    head->priority = -1;
    *head->task = '\0';

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
            deleteList(head);
            head = NULL;
            return 0; 
        default:
            continue;
        }
        

        
    }

    return 0; 
}


int generateID(Ticket *head)
{
    int min = 100;
    int max = 999;
    int number;
    int isDuplicate; 

    do 
    {
        isDuplicate = 0; // assume the ID is unique
        int number = (rand() % (max - min + 1)) + min; 

        // check if ID is unique
        Ticket *temp = head;

        while (temp != NULL) 
        {
            if (temp->id == number)
            {
                isDuplicate = 1;
                break;
            }

            temp = temp->next;
        }
    } while (isDuplicate); // while isDuplicate == 1

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
    Ticket *temp = head;

    // go to the last node, then create an additional node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = (Ticket *)malloc(sizeof(Ticket));
    temp->next->next = NULL; // this sets the ending point of the linkedlist

    // get info for the ticket
    char enteredTask[MAX];
    int enteredPriority;

    printf("\nEnter Ticket: ");
    fgets(enteredTask, MAX, stdin);

    printf("Enter priority (1: Basic, 2: Medium, 3: Important, 4: Crucial):  ");
    scanf("%d", &enteredPriority);
    clearBuffer();

    // * by using next->, the data is being shifted by a node to keep the head node empty 
    // check if user entered a valid priority ranking, default is 1
    if ((1 <= enteredPriority) && (enteredPriority <= 4))
    {
        temp->next->priority = enteredPriority;
    }
    else
    {
        temp->next->priority = 1;
    }

    strcpy(temp->next->task, enteredTask); // this is how you copy strings over into a node
    temp->next->id = generateID(head);

    return;
}


void viewTickets(Ticket *head)
{
    Ticket *temp = head;

    while (temp->next != NULL)
    {   
        printf("\nTicket: %s", temp->next->task);
        printf("ID: %d\n", temp->next->id);
        printf("Priority: %d\n", temp->next->priority);
        printf("\n"); // for spacing

        // go to the next node
        temp = temp->next;
    }

    return;
}

void deleteList(Ticket *head)
{
    Ticket *temp; 

    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}