
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
#include "account.h"
#include "accountTicketingUI.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void getAccount(struct Account* database, struct Account account[], int max) {
	int NewNumber, i, greater=0 ;
	for (i = 0; i < max; i++) {//Find the greater account number
		if (database[i].accountNum>greater) {
			greater = database[i].accountNum;
		}
	}
	NewNumber = greater + 1;
	account->accountNum= NewNumber;
	printf("\nNew Account Data (Account#:%d)\n",NewNumber);
	printf("----------------------------------------");
	printf("\nEnter the account type (A=Agent | C=Customer): ");
	account->acType= getCharOption("AC");
}

void getUserLogin(struct Account* login) {
	printf("\nUser Login Data Input\n");
	printf("----------------------------------------\n");
	getuser(login);
	printf("Enter the display name (30 chars max): ");
	getCString(login->loggin.name, 0, 30);
	getpassword(login);

	}

void getuser(struct Account* login) {
	int space = 0, i, l = 0;
		space = 0;
		do {
			space = 0;
		printf("Enter user login (10 chars max): ");  // Check that the user login does not have spaces
		getCString(login->loggin.user, 0, 10);
		l = strlen(login->loggin.user);
		for (i = 0; i < l; i++) {
			if (login->loggin.user[i] == ' ') {
				printf("ERROR:  The user login must NOT contain whitespace characters.\n");
				space = 1;
			}
		}
	} while (space == 1);
}

void getpassword(struct Account* login) {
	int i,flagupp = 0, flagpunc = 0, flaglow = 0, digit = 0, invalidPass = 1;
	//printf("\n");
	do {
		flagupp = 0, flagpunc = 0, flaglow = 0, digit = 0, invalidPass = 1;
		printf("Enter the password (must be 8 chars in length): ");
		getCString(login->loggin.password, 8, 8);
		for (i = 0; i < 8; i++) {
			if (isdigit(login->loggin.password[i])) {
				digit++;
			}
			if (isalpha(login->loggin.password[i]) && isupper(login->loggin.password[i])) {
				flagupp++;
			}
			if (isalpha(login->loggin.password[i]) && !isupper(login->loggin.password[i])) {
				flaglow++;
			}
			if (ispunct(login->loggin.password[i])) {
				flagpunc++;
			}
		}
		if (digit == 2 && flagpunc == 2 && flagupp == 2 && flaglow == 2) {
			invalidPass = 0;
		}
		else {
			invalidPass = 1;
			printf("SECURITY: Password must contain 2 of each:");
			printf("\n          Digit: 0-9");
			printf("\n          UPPERCASE character");
			printf("\n          lowercase character");
			printf("\n          symbol character: !@#$%%^&*\n");
		}
	} while (invalidPass == 1);
}

void getDemographic(struct Account*demo) {
	
	printf("\nDemographic Data Input\n");
	printf("----------------------------------------\n");
	printf("Enter birth year (current age must be between 18 and 110): ");
	demo->Demo.birthYear= getIntFromRange(1911,(currentYear() - 18));
	printf("Enter the household Income: $");
	demo->Demo.inccome= getPositiveDouble();
	getCountry(demo);
	
}

void getCountry(struct Account* demo) {
	int len = 0, i;
	printf("Enter the country (30 chars max.): ");
	getCString(demo->Demo.country, 1, 30);
	len = strlen(demo->Demo.country);
	for (i = 0; i < len; i++) {
		demo->Demo.country[i] = toupper(demo->Demo.country[i]);
	}
}

void archiveremovedAccount(struct Account* accounts, int remove) {

	int index = remove - 1;
	const char filename[] = "accounts_arc.txt";

	FILE* fp = fopen(filename, "a");
	if (fp != NULL) {

		fprintf(fp, "%d~%c~%s~%s~%s~%d~%lf~%s\n", accounts[index].accountNum, accounts[index].acType, accounts[index].loggin.name, accounts[index].loggin.user, accounts[index].loggin.password, accounts[index].Demo.birthYear, accounts[index].Demo.inccome, accounts[index].Demo.country);
			
		//printf("\n\n*** account %d archived ***\n\n", accounts[index].accountNum);

	}
	else {
		printf("ERROR; Unable to open the file for wrinting");
	}
	fclose(fp);
	fp = NULL;
}

void recreateAccountsfileagent(struct Account* accounts, int size) {
	printf("\nSaving Agent session modifications...");
	int i = 0,  saved = 0;
	//const char filename[] = "accountswriteAgent.txt";
	const char filename[] = "accounts.txt";

	FILE* fp = fopen(filename, "w");
	if (fp != NULL) {

		for (i = 0; i < size; i++) {
			if (accounts->accountNum!= 0) {
			
				fprintf(fp, "%d~%c~%s~%s~%s~%d~%lf~%s\n", accounts[i].accountNum, accounts[i].acType, accounts[i].loggin.name, accounts[i].loggin.user, accounts[i].loggin.password, accounts[i].Demo.birthYear, accounts[i].Demo.inccome, accounts[i].Demo.country);
				saved = saved + 1;
			
			}
		}

		printf("\n   %d accounts  saved.", saved);

	}
	else {
		printf("ERROR; Unable to open the file for wrinting");
	}
	fclose(fp);
	fp = NULL;
}
