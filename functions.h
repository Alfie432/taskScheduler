#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

int generateID(Ticket *head);
void clearBuffer(void);
void addTicket(Ticket *head);
void viewTickets(Ticket *head);
void deleteList(Ticket *head);
void removeTicket(Ticket *head, int ID);
int getID(void);
void orderList(Ticket *head);

#endif 