// ===================================================================================
//  Assignment: 2 //  Milestone : 4
// ===================================================================================
//  Student Name  : Edgar David Garcia Torres
//  Student ID    : 104433206
//  Student Email : edgarciat-torres@myseneca.ca
//  Course Section: ZZA
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "accountTicketingUI.h"
#include "ticket.h"

void listActivetickets(struct AccountTicketingData* account) {
	//based on the status being open(will have a value of 1)
	int i = 0, ticketNum;
	int index = 0;
	char open[] = "ACTIVE";//CHANGED OPEN
	do {
		int noprint = 0;
		printf("\n------ ----- --------------- ------ ------------------------------ --------");
		printf("\nTicket Acct# Display Name    Status Subject                        Messages");
		printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
		//check which status are in open
		for (i = 0; i < account->TICKET_MAX_SIZE; i++) {   
			if (account->tickets[i].Status == 1) {
				printf("%06d %5d %-15s %-6s %-30s %5d\n", account->tickets[i].TIckNum, account->tickets[i].NumAcc, account->tickets[i].Mes->MessName, open, account->tickets[i].Subject, account->tickets[i].Counter);
			}
		}
		printf("------ ----- --------------- ------ ------------------------------ --------\n");

		printf("\nEnter the ticket number to view the messages or");
		printf("\n0 to return to previous menu: ");
		ticketNum = getPositiveInteger();
		index = findticketIndex(ticketNum, account);
		if (ticketNum == 0) {
			//goto E;
		}
		if (index == 0 && ticketNum !=0) {
			printf("\nERROR: Invalid ticket number.\n\n");
			pauseExecution();
		}
		if (index > 0 && ticketNum != 0) {
			char actypC[9] = "CUSTOMER";
			char actypA[9] = "AGENT";
			
			printf("\n================================================================================");
			printf("\n%06d (ACTIVE) Re: %s", account->tickets[index - 1].TIckNum, account->tickets[index - 1].Subject);//CHANGED OPEN
			printf("\n================================================================================");

			for (i = 0; i < 20; i++) { 
				if (account->tickets[index - 1].Status == 1) {
					if (account->tickets[index - 1].Mes[i].MessAcType == 'C') {
						printf("\n%s (%s):", actypC, account->tickets[index - 1].Mes->MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
						if (account->tickets[index-1].Counter ==(i+1)) {
							noprint = 1;
						}
						if ((i + 1) % 5 == 0 && i != 0 && noprint == 0) {
							printf("\n");
							pauseExecution();
						}
					}
					noprint = 0;
					if (account->tickets[index - 1].Mes[i].MessAcType == 'A') {
						printf("\n%s (%s):", actypA, account->tickets[index - 1].Mes[i].MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
						if  (account->tickets[index - 1].Counter == (i + 1)) {
							noprint = 1;
						}
						if ((i + 1) % 5 == 0 && i != 0 && noprint==0) {
							printf("\n");
							pauseExecution();
						}
					}
					noprint = 0;
				}
			}
			printf("\n");
			pauseExecution();
		}
	} while (ticketNum != 0);
}

void listClosedtickets(struct AccountTicketingData* account) {
	//based on the status being closed (will have a value of 0)
	int i = 0, ticketNum;
	int index = 0;
	char closed[] = "CLOSED";
	do {
		printf("\n------ ----- --------------- ------ ------------------------------ --------");
		printf("\nTicket Acct# Display Name    Status Subject                        Messages");
		printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
		//check which status are in open
		for (i = 0; i < account->TICKET_MAX_SIZE; i++) {  
			if (account->tickets[i].Status == 0 && account->tickets[i].TIckNum!=0) {
				printf("%06d %5d %-15s %-6s %-30s %5d\n", account->tickets[i].TIckNum, account->tickets[i].NumAcc, account->tickets[i].Mes->MessName, closed, account->tickets[i].Subject, account->tickets[i].Counter);
			}
		}
		printf("------ ----- --------------- ------ ------------------------------ --------\n");

		printf("\nEnter the ticket number to view the messages or");
		printf("\n0 to return to previous menu: ");
		ticketNum = getPositiveInteger();
		index = findticketIndex(ticketNum, account);
		if (ticketNum == 0) {
			//goto E;
		}
		if (index == 0 && ticketNum!=0) {
			printf("\nERROR: Invalid ticket number.\n\n");
			pauseExecution();
		}
		if (index > 0 && ticketNum != 0) {
			char actypC[9] = "CUSTOMER";
			char actypA[9] = "AGENT";

			printf("\n================================================================================");
			printf("\n%06d (CLOSED) Re: %s", account->tickets[index - 1].TIckNum, account->tickets[index - 1].Subject);
			printf("\n================================================================================");

			for (i = 0; i < 20; i++) {  //TEST 30
				int noprint = 0;
				if (account->tickets[index - 1].Status == 0) {
					if (account->tickets[index - 1].Mes[i].MessAcType == 'C') {
						printf("\n%s (%s):", actypC, account->tickets[index - 1].Mes->MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
						if (account->tickets[index - 1].Counter == (i + 1)) {
							noprint = 1;
						}
						if ((i + 1) % 5 == 0 && i != 0 && noprint == 0) {
							printf("\n");
							pauseExecution();
						}
					}
					noprint = 0;
					if (account->tickets[index - 1].Mes[i].MessAcType == 'A') {
						printf("\n%s (%s):", actypA, account->tickets[index - 1].Mes[i].MessName);
						printf("\n   %s\n", account->tickets[index - 1].Mes[i].MessDetail);
						if (account->tickets[index - 1].Counter == (i + 1)) {
							noprint = 1;
						}
						if ((i + 1) % 5 == 0 && i != 0 && noprint == 0) {
							printf("\n");
							pauseExecution();
						}
					}
					noprint = 0;
				}

			}
			printf("\n");
			pauseExecution();

		}

	} while (ticketNum != 0);

}

void manageTickets(struct AccountTicketingData* Tickets, struct Account* logged) {
	int ticketNum, index=0, selection=6;
	printf("\nEnter ticket number: ");
	ticketNum = getIntFromRange(0, 99999);

	do {
		
		//LOOK FOR THE INDEX OF THE TICKET ENTERED
		index = findticketIndex(ticketNum, Tickets);
		if (index == 0) {
			printf("\nThat ticket number is not in the list.\n\n");
			pauseExecution();
			selection = 0;
			goto K;
		}
		printf("\n----------------------------------------");
		printf("\nTicket %06d - Update Options", ticketNum);
		printf("\n----------------------------------------");

		if (Tickets->tickets[index - 1].Status == 0) {
		printf("\nStatus  : CLOSED");
		}
		if (Tickets->tickets[index - 1].Status == 1) {
		printf("\nStatus  : ACTIVE");
		}
		printf("\nSubject : %s", Tickets->tickets[index - 1].Subject);
		printf("\nAcct#   : %d", Tickets->tickets[index - 1].NumAcc);
		printf("\nCustomer: %s", Tickets->tickets[index - 1].Mes[0].MessName);
		printf("\n----------------------------------------");
		printf("\n1) Add a message");
		printf("\n2) Close ticket");
		printf("\n3) Re-open ticket");
		printf("\n0) Done");
		printf("\nSelection: ");

		selection = getIntFromRange(0, 3);
		if (selection == 1) {//ADD MESSAGE
			int i, fin = 0, free =0;
			if (Tickets->tickets[index-1].Status==0) {
				printf("\nERROR: Ticket is closed - new messages are not permitted.\n");
			}
			else {
				//check in which position place the next message 
				for (i = 0; i < 20; i++) { // TEST 30 
					if (Tickets->tickets[index - 1].Mes[i].MessAcType == 0 && fin == 0) {
						free = i + 1;
						if (free != 0) {
							fin = 1;
						}
					}
				}
				if (free == 0) {      //Free is the position of the free tickets message + 1
					printf("\nERROR: Message limit has been reached, call ITS Support!\n");
				}
				if (free != 0) {// if there is a free space then receive the new message detail.
					printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
					getCString(Tickets->tickets[index - 1].Mes[free - 1].MessDetail, 1, 150);
					Tickets->tickets[index - 1].Mes[free - 1].MessAcType = 65;
					strcpy(Tickets->tickets[index - 1].Mes[free - 1].MessName, logged->loggin.name);
					Tickets->tickets[index - 1].Counter++;
				}
			}
		}
		if (selection == 2) {//CLOSE TICKET
			char close, closemessage;
			if (Tickets->tickets[index - 1].Status == 0) {
				printf("\nERROR: Ticket is already closed!\n");
			}
			if (Tickets->tickets[index - 1].Status == 1) {
				printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
				close = getCharOption("YN");
				int free = 0,i,fin=0;
				if (close == 'Y') {// CLOSE THE TICKET 
					Tickets->tickets[index - 1].Status = 0;
					for (i = 0; i < 20; i++) { // TEST 30 
						if (Tickets->tickets[index - 1].Mes[i].MessAcType == 0 && fin == 0) {
							free = i + 1;
							if (free != 0) {
								fin = 1;
							}
						}
					}
					if (Tickets->tickets[index - 1].Counter == 20) { // there is no space for messages
						// do nothing 
					}
					if (Tickets->tickets[index - 1].Counter < 20) {//there is space for messages 
						printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
						closemessage = getCharOption("YN"); 
						if (closemessage == 'Y') {//Write the message
						/********************************************************************************/
							printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
							getCString(Tickets->tickets[index - 1].Mes[free - 1].MessDetail, 1, 150);
							Tickets->tickets[index - 1].Mes[free - 1].MessAcType = 65;
							strcpy(Tickets->tickets[index - 1].Mes[free - 1].MessName, logged->loggin.name);
							Tickets->tickets[index - 1].Counter++;
						/******************************************************************************/
						}
					}
					printf("\n*** Ticket closed! ***\n");
				}
			}

		}
		if (selection == 3) {//RE OPEN TICKET. 
			char open;
			if (Tickets->tickets[index - 1].Status == 1) {
				printf("\nERROR: Ticket is already active!\n");
			}
			if (Tickets->tickets[index - 1].Status == 0) {
				printf("\nAre you sure you RE-OPEN this closed ticket? ([Y]es|[N]o): ");
				open = getCharOption("YN");
				if (open == 'Y') { // OPEN THE TICKET
					Tickets->tickets[index - 1].Status = 1;
					printf("\n*** Ticket re-opened! ***\n");
				}
			}
		}
		if (selection == 0) {// GET OUT 
		}
	} while (selection != 0);
K:;
}

void listNewtickets(struct AccountTicketingData* account) {
	//The ticket status must be open (will have a value of 1) and there will be only one (1) message.
	int i = 0, ticketNum, index = 0;
	char open[] = "ACTIVE";// CHANGED OPEN
	do {
		printf("\n------ ----- --------------- ------ ------------------------------ --------");
		printf("\nTicket Acct# Display Name    Status Subject                        Messages");
		printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
		//check which status are in open
		for (i = 0; i < account->TICKET_MAX_SIZE; i++) {
			if (account->tickets[i].Counter == 1 && account->tickets[i].Status == 1) {
				printf("%06d %5d %-15s %-6s %-30s %5d\n", account->tickets[i].TIckNum, account->tickets[i].NumAcc, account->tickets[i].Mes->MessName, open, account->tickets[i].Subject, account->tickets[i].Counter);
			}
		}
		printf("------ ----- --------------- ------ ------------------------------ --------\n");

		printf("\nEnter the ticket number to view the messages or");
		printf("\n0 to return to previous menu: ");
		ticketNum = getPositiveInteger();
		index = findticketIndex(ticketNum, account);

		if (index == 0 && ticketNum!=0) {
			printf("\nERROR: Invalid ticket number.\n\n");
			pauseExecution();
		}
		if (index > 0 && ticketNum != 0) {
			char actypC[9] = "CUSTOMER";
			char actypA[9] = "AGENT";

			printf("\n================================================================================");
			printf("\n%06d (ACTIVE) Re: %s", account->tickets[index - 1].TIckNum, account->tickets[index - 1].Subject);//CHANGED OPEN
			printf("\n================================================================================");

			if (account->tickets[index - 1].Mes->MessAcType == 'C') {
				printf("\n%s (%s):", actypC, account->tickets[index - 1].Mes->MessName);
				printf("\n   %s\n", account->tickets[index - 1].Mes->MessDetail);
			}
			if (account->tickets[index - 1].Mes->MessAcType == 'A') {
				printf("\n%s (%s):", actypA, account->tickets[index - 1].Mes->MessName);
				printf("\n   %s\n", account->tickets[index - 1].Mes->MessDetail);
			}
			printf("\n");
			pauseExecution();

		}

	} while (ticketNum != 0);

}

int findticketIndex(int ticketNum, struct AccountTicketingData* account) {
	int max = account->TICKET_MAX_SIZE, i, index = 0;
	for (i = 0; i < max; i++) {
		if (ticketNum == account->tickets[i].TIckNum) {
			index = i + 1;
		}
	}
	return index;
}

void createnewTicket(struct AccountTicketingData* tickets, struct Account* loged) {
	int i, maxT = tickets->TICKET_MAX_SIZE, found=0, notfound = 1;
	do {   //Check if there is a space for a new ticket
		for (i = 0; i < maxT; i++) {
			if (tickets->tickets[i].TIckNum == 0) {
				found = i;//found is the position of the free spot
				goto L;
			}
		}L:
		if (found == 0) {//DID NOT FIND A FREE SPOT 
			printf("\nERROR: Ticket listing is FULL, call ITS Support!\n\n");
			notfound = 0;
		}
		if (found > 0 && found <= maxT) {//FOUND A FREE SPOT IN i
			//Add a ticket number
			int NewNumber, i, greater = 0;
			for (i = 0; i < maxT; i++) {//Find the greater ticket number
				if (tickets->tickets[i].TIckNum> greater) {
					greater = tickets->tickets[i].TIckNum;
				}
			}

			NewNumber = greater + 1;//this is the new ticket number 
			tickets->tickets[found].TIckNum = NewNumber;
			tickets->tickets[found].NumAcc = loged->accountNum;
			tickets->tickets[found].Status = 1;
			printf("\nNew Ticket (Ticket#:%06d)",NewNumber);
			printf("\n----------------------------------------");
			printf("\nEnter the ticket SUBJECT (30 chars. maximum): ");
			getCString(tickets->tickets[found].Subject,1,30);
			printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
			getCString(tickets->tickets[found].Mes[0].MessDetail, 1, 150);
			tickets->tickets[found].Counter = 1;
			tickets->tickets[found].Mes[0].MessAcType = 67;
			strcpy(tickets->tickets[found].Mes[0].MessName, loged->loggin.name);
			
			printf("\n*** New ticket created! ***\n\n");

			notfound = 0;
		}
	} while (notfound == 1);
}

void modifyTicket(struct AccountTicketingData* tickets, struct Account* loged) {
	int ticketNum, i, myticket=0 ,index=0, option=5;
	
		printf("\nEnter ticket number: ");
		ticketNum = getIntFromRange(1, 99999);
		for (i = 0; i < tickets->TICKET_MAX_SIZE; i++) {// look for permision to modify the ticket
			if (ticketNum == tickets->tickets[i].TIckNum && loged->accountNum == tickets->tickets[i].NumAcc) {
				myticket = 1;
			}
		}
		do {
			if (myticket == 1) {//MODIFY THE TICKET
				index = findticketIndex(ticketNum, tickets);
				if (tickets->tickets[index - 1].Status == 0) {
					printf("\nERROR: Ticket is closed - changes are not permitted.\n\n");
					option = 0;
					pauseExecution();
					goto F;

				}
				else {

					printf("\n----------------------------------------");
					printf("\nTicket %06d - Update Options", ticketNum);
					printf("\n----------------------------------------");
					if (tickets->tickets[index - 1].Status == 1) {
						printf("\nStatus  : ACTIVE");
					}
					if (tickets->tickets[index - 1].Status == 0) {
						printf("\nStatus  : CLOSED");
					}
					printf("\nSubject : %s", tickets->tickets[index - 1].Subject);
					printf("\n----------------------------------------");
					printf("\n1) Modify the subject");
					printf("\n2) Add a message");
					printf("\n3) Close ticket");
					printf("\n0) Done");
					printf("\nSelection: ");
					option = getIntFromRange(0, 3);
					int free = 0, fin = 0;//1 FOR THE  MOMENT
					if (option == 1) {//modify the subject 
						printf("\nEnter the revised ticket SUBJECT (30 chars. maximum): ");
						getCString(tickets->tickets[index - 1].Subject, 1, 30);
					}
					if (option == 2) {//Add a message
							//check in which position place the next message 
							for (i = 0; i < 20; i++) { // TEST 30 
								if (tickets->tickets[index - 1].Mes[i].MessAcType == 0 && fin == 0) {
									free = i + 1;
									if (free != 0) {
										fin = 1;
									}
								}
							}
						if (free == 0) {      //Free is the position of the free tickets message + 1
							printf("\nERROR: Message limit has been reached, call ITS Support!\n");
						}
						if (free != 0) {// if there is a free space then receive the new message detail.
							printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
							getCString(tickets->tickets[index - 1].Mes[free - 1].MessDetail, 1, 150);
							tickets->tickets[index - 1].Mes[free - 1].MessAcType = 67;
							strcpy(tickets->tickets[index - 1].Mes[free - 1].MessName, loged->loggin.name);
							tickets->tickets[index - 1].Counter++;
						}
					}
				char close;
				char closemessage;
				if (option == 3) {//Close ticket

					printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
					close = getCharOption("YN");
					if (close == 'Y') {
						tickets->tickets[index - 1].Status = 0;

						//***************************************************************************************
						for (i = 0; i < 20; i++) { //LOOK IF THERE IS A FREE SPACE 
							if (tickets->tickets[index - 1].Mes[i].MessAcType == 0 && fin == 0) {
								free = i + 1;
								if (free != 0) {
									fin = 1;
								}
								//goto Out;
							}
						}
						if (free != 0) {//If there is afree space ask fot the new message
							printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
							closemessage = getCharOption("YN");
							if (closemessage == 'Y') {
								// if there is a free space then receive the new message detail.
							printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
								getCString(tickets->tickets[index - 1].Mes[free - 1].MessDetail, 1, 150);
								tickets->tickets[index - 1].Mes[free - 1].MessAcType = 67;
								strcpy(tickets->tickets[index - 1].Mes[free - 1].MessName, loged->loggin.name);
								tickets->tickets[index - 1].Counter++;
							}
						}
						//***************************************************************************************

						printf("\n*** Ticket closed! ***\n\n");
						pauseExecution();
						goto F;
						option = 0;
					}
				}
			}
				}
			else {
				printf("\nERROR: Invalid ticket number - you may only modify your own ticket.\n\n");
				pauseExecution();
				goto F;
				option = 0;

			}
			if (option == 0) {
				printf("\n");
				pauseExecution();// last added
			}
			
		} while (option!=0);
	F:;
}

void removeticketsofaccount(struct AccountTicketingData* tickets, int removeaccount) {
//Archive the ticket in tickets_arc.txt" before removing the ticket from memory.



//this function triggers when removing an account
//Search for every ticket that is related to the account to remove
	int i,e, flag =0, check = 0;
	for (i = 0; i < tickets->TICKET_MAX_SIZE; i++) {
		flag = 0;
		if (tickets->tickets[i].NumAcc == removeaccount) { //remove if status is active or closed

			
			const char filename[] = "tickets_arc.txt";
			FILE* fp = fopen(filename, "a");
			if (fp != NULL) {// store the information of the tickets before removing them 
				
				check = checkStoredticket(tickets->tickets[i].TIckNum, tickets->TICKET_MAX_SIZE);
				//printf("\nEliminating   %d state is %d", tickets->tickets[i].TIckNum, tickets->tickets[i].Status);
			if (tickets->tickets[i].Status == 0 && check == 0) {// if the status is CLOSED archive the ticket. and the ticket is not stored yet.
				//printf("\n   Sending  %d  to achive", tickets->tickets[i].TIckNum);
				fprintf(fp, "%d|%d|%d|%s|%d|", tickets->tickets[i].TIckNum, tickets->tickets[i].NumAcc, tickets->tickets[i].Status, tickets->tickets[i].Subject, tickets->tickets[i].Counter);
				flag = 1;
			}
				tickets->tickets[i].Counter = 0;
				tickets->tickets[i].NumAcc = 0;
				tickets->tickets[i].Status = 0;
				strcpy(tickets->tickets[i].Subject, "");
				tickets->tickets[i].TIckNum = 0;

				if (tickets->tickets[i].Status == 0) {// if the status is CLOSED archive the ticket.
					for (e = 0; e < 20; e++) {
						if (tickets->tickets[i].Mes[e].MessAcType != 0) {// store the information of the tickets before removing them 
							if (flag == 1) {// if the status is CLOSED archive the ticket.
								fprintf(fp, "%c|%s|%s|", tickets->tickets[i].Mes[e].MessAcType, tickets->tickets[i].Mes[e].MessName, tickets->tickets[i].Mes[e].MessDetail);
							}
							tickets->tickets[i].Mes[e].MessAcType = 0;
							strcpy(tickets->tickets[i].Mes[e].MessDetail, "");
							strcpy(tickets->tickets[i].Mes[e].MessName, "");
						}
					}
					if (flag==1) {
						fprintf(fp, "\n");
					}
				}
				
				fclose(fp);
				fp = NULL;
			}
			
		}
	}
	
}

int checkStoredticket(int numTicket, int max) { // thi fuction check if a ticket number already is stored in tickets_acr.txt

	struct Ticket stored[50] = { {0} };


	int i = 0, e = 0,  result = 0;
	char ch;
	char mode;

	const char filetickets[] = "tickets_arc.txt";

	FILE* fp = fopen(filetickets, "r");
	if (fp != NULL) {
		for (i = 0; i < max; i++) {

			fscanf(fp, "%d|%d|%d|%[^|]|%d|%c", &stored[i].TIckNum, &stored[i].NumAcc, &stored[i].Status, stored[i].Subject, &stored[i].Counter, &ch);
			for (e = 0; e < 20; e++) {
				if (ch != '\n') {
					stored[i].Mes[e].MessAcType = ch;
					fscanf(fp, "%c%[^|]|%[^|]|%c", &mode, stored[i].Mes[e].MessName, stored[i].Mes[e].MessDetail, &ch);
				}
				else {
					goto k;
				}
			}
		k:;
		}
		fclose(fp);
		fp = NULL;
	}
	else {
		printf("\nERROR unable to read");
	}
	//At this point we already have the reading of the ticket_arc.tx in the struct stored.
	// we are  going to review the struct stored to see if already contains the ticket number recievid
	for (i = 0; i < max; i++) {
		if (numTicket == stored[i].TIckNum) {
			result = 1;
			//printf("\n %d is in the archive", numTicket);
		}
	}

	return result;

}

void recreateTicketsfilecustomer(struct AccountTicketingData* tickets) {
	printf("\nSaving session modifications...");
	int i = 0, e=0, saved =0, fin =0;
	//const char filename[] = "ticketswrite.txt";
	const char filename[] = "tickets.txt";
	
	FILE* fp = fopen(filename, "w");
	if (fp != NULL) {

		for (i = 0; i < 17; i++) {
			if (tickets->tickets[i].TIckNum != 0) {
				fin = 0;
				fprintf(fp, "%d|%d|%d|%s|%d|", tickets->tickets[i].TIckNum, tickets->tickets[i].NumAcc, tickets->tickets[i].Status, tickets->tickets[i].Subject, tickets->tickets[i].Counter);
				saved = saved + 1;
				if (tickets->tickets[i].Mes[e].MessAcType != 0 && fin==0) {
					for (e = 0; e < 20; e++) {
						if (tickets->tickets[i].Mes[e].MessAcType != 0) {
						//if (tickets->tickets[i].Mes[e].MessAcType == 'A' || tickets->tickets[i].Mes[e].MessAcType == 'C') {
							fprintf(fp, "%c|%s|%s|", tickets->tickets[i].Mes[e].MessAcType, tickets->tickets[i].Mes[e].MessName, tickets->tickets[i].Mes[e].MessDetail);
						}
					}
					fprintf(fp, "\n");
				}
			}
		}

		printf("\n   %d tickets saved.", saved);
		fclose(fp);
		fp = NULL;
	}
	else {
		printf("ERROR; Unable to open the file for wrinting");
	}
	
}

void recreateTicketsfileAgent(struct AccountTicketingData* tickets, int max) {
	
	int i = 0, e = 0, saved = 0, fin = 0;
	//const char filename[] = "ticketswriteAgent.txt";
	const char filename[] = "tickets.txt";

	FILE* fp = fopen(filename, "w");
	if (fp != NULL) {

		for (i = 0; i < max; i++) {
			if (tickets->tickets[i].TIckNum != 0) {
				fin = 0;
				fprintf(fp, "%d|%d|%d|%s|%d|", tickets->tickets[i].TIckNum, tickets->tickets[i].NumAcc, tickets->tickets[i].Status, tickets->tickets[i].Subject, tickets->tickets[i].Counter);
				saved = saved + 1;
				if (tickets->tickets[i].Mes[e].MessAcType != 0 && fin == 0) {
					for (e = 0; e < 20; e++) {
						if (tickets->tickets[i].Mes[e].MessAcType != 0) {
							//if (tickets->tickets[i].Mes[e].MessAcType == 'A' || tickets->tickets[i].Mes[e].MessAcType == 'C') {
							fprintf(fp, "%c|%s|%s|", tickets->tickets[i].Mes[e].MessAcType, tickets->tickets[i].Mes[e].MessName, tickets->tickets[i].Mes[e].MessDetail);
						}
					}
					fprintf(fp, "\n");
				}
			}
		}
		fclose(fp);
		fp = NULL;
		printf("\n   %d tickets saved.", saved);

	}
	else {
		printf("ERROR; Unable to open the file for wrinting");
	}
	
}

void viewarchivedAccounts() {
	const char filename[] = "accounts_arc.txt";
	int c, nrecs=0;

	FILE* fp = fopen(filename, "r");
	if (fp != NULL) {
		nrecs = 0;
		do {
			c = fgetc(fp);
			if (c != EOF) {
				if ((char)c == '\n')
					nrecs++;
			}
		} while (feof(fp) == 0);
		
		fclose(fp);
	}
	printf("\nThere are %d account(s) currently archived.\n\n", nrecs);
}

void viewarchivedTickets() {
	const char filename[] = "tickets_arc.txt";
	int c, nrecs=0, messages=0;

	FILE* fp = fopen(filename, "r");
	if (fp != NULL) {
		nrecs = 0;
		do {
			c = fgetc(fp);
			if (c != EOF) {
				if ((char)c == '\n')
					nrecs++;
			}
		} while (feof(fp) == 0);
		fclose(fp);
	}
//COUNT THE MESSAGES
	messages = countTicketMessages(nrecs);

	printf("\nThere are %d ticket(s) and a total of %d message(s) archived.\n\n", nrecs, messages);
}

int  countTicketMessages(int max) {

	struct Ticket tick[17] = { {0} };

		int i = 0, e = 0,   messages =0;
		char ch;
		char mode;
		
		const char filetickets[] = "tickets_arc.txt";

		FILE* fp = fopen(filetickets, "r");
		if (fp != NULL) {
			for (i = 0; i < max; i++) {

				fscanf(fp, "%d|%d|%d|%[^|]|%d|%c", &tick[i].TIckNum, &tick[i].NumAcc, &tick[i].Status, tick[i].Subject, &tick[i].Counter, &ch);
				for (e = 0; e < 20; e++) {
					if (ch != '\n') {
						messages = messages + 1;

						tick[i].Mes[e].MessAcType = ch;
						fscanf(fp, "%c%[^|]|%[^|]|%c", &mode, tick[i].Mes[e].MessName, tick[i].Mes[e].MessDetail, &ch);
						
					}
					else {
						goto k;
					}
				}
			k:;
			}
			fclose(fp);
		}
		else {
			//printf("\nERROR unable to read");
		}
		
		fp = NULL;

		return messages;
	}

void archiveclosedTickets(struct AccountTicketingData* tickets) {

	int i = 0, e = 0, saved = 0;
	const char filename[] = "tickets_arc.txt";

	FILE* fp = fopen(filename, "a");
	if (fp != NULL) {

		for (i = 0; i < tickets->TICKET_MAX_SIZE; i++) {
		
			if (tickets->tickets[i].TIckNum != 0 && tickets->tickets[i].Status == 0) {
					fprintf(fp, "%d|%d|%d|%s|%d|", tickets->tickets[i].TIckNum, tickets->tickets[i].NumAcc, tickets->tickets[i].Status, tickets->tickets[i].Subject, tickets->tickets[i].Counter);
				saved = saved + 1;


				for (e = 0; e < 20; e++) {
					if (tickets->tickets[i].Mes[e].MessAcType != 0) {// store the information of the tickets before removing them 
						
							fprintf(fp, "%c|%s|%s|", tickets->tickets[i].Mes[e].MessAcType, tickets->tickets[i].Mes[e].MessName, tickets->tickets[i].Mes[e].MessDetail);

					}
				}
				//if (flag == 1) {
					fprintf(fp, "\n");
				//}
			}
		}

		printf("\n*** %d tickets archived ***\n\n", saved);
		fclose(fp);
		fp = NULL;
	}
	else {
		printf("ERROR; Unable to open the file for wrinting");
	}
	

}




