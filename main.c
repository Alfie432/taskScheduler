#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


int main(void)
{
    srand(time(NULL));
    int choice;
    int id;

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
            id = getID();
            removeTicket(head, id);
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