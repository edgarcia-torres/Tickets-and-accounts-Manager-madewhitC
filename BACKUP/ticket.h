// ===================================================================================
//  Assignment: 2 //  Milestone : 4
// ===================================================================================
//  Student Name  : Edgar David Garcia Torres
//  Student ID    : 104433206
//  Student Email : edgarciat-torres@myseneca.ca
//  Course Section: ZZA
// ===================================================================================
#ifndef TICKET_H_
#define TICKET_H_

#include "accountTicketingUI.h"


void listActivetickets(struct AccountTicketingData* account);

void listClosedtickets(struct AccountTicketingData* account);

void manageTickets(struct AccountTicketingData* Tickets, struct Account* logged);

void listNewtickets(struct AccountTicketingData* account);

int findticketIndex(int ticketNum, struct AccountTicketingData* account);

void createnewTicket(struct AccountTicketingData* tickets, struct Account* loged);

void modifyTicket(struct AccountTicketingData* tickets, struct Account* loged);

void removeticketsofaccount(struct AccountTicketingData* tickets, int removeaccount);

void recreateTicketsfilecustomer(struct AccountTicketingData* tickets);

void recreateTicketsfileAgent(struct AccountTicketingData* tickets, int max);

void viewarchivedAccounts();

void viewarchivedTickets();

int  countTicketMessages(int max);

void archiveclosedTickets(struct AccountTicketingData* tickets);

#endif // 