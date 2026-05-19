#include <stdio.h>
#include "functions.h"

int generateID(Ticket *head)
{
    int min = 100;
    int max = 999;
    int number;
    int isDuplicate; 

    do 
    {
        isDuplicate = 0; // assume the ID is unique
        number = (rand() % (max - min + 1)) + min; 

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

    if (head->next == NULL) 
    {
        printf("\nNo tickets assigned.\n");
        return;
    }

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


void removeTicket(Ticket *head, int ID)
{
    // if ticket list in empty
    if (head->next == NULL)
    {
        printf("\nNo tickets assigned.\n");
        return;
    }

    int complete = 0;
    Ticket *temp = head;

    while (temp->next->next != NULL)
    {
        if (temp->next->id == ID)
        {
            // when the ticket is found
            Ticket *before = temp;
            temp = temp->next; // go to the next node

            // if next node in NULL, then temp is the last node
            // else, move temp by 1 more node
            if (temp->next == NULL)
            {
                before->next = NULL;
                free(temp);
            }
            else
            {
                temp = temp->next; // go to the next node
                before->next = temp;
            }
            
            printf("\nTicked %d has been removed successfully.\n", ID);
            return; // break out of function to avoid wasting performance
        }

        temp = temp->next;
    }

    printf("\nTicket not found.\n");
}


int getID(void)
{
    int id;

    printf("Enter the ID of ticket to remove: ");
    scanf("%d", &id);
    clearBuffer();

    return id;
}


