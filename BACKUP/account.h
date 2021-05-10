// ===================================================================================
//  Assignment: 2 //  Milestone : 4
// ===================================================================================
//  Student Name  : Edgar David Garcia Torres
//  Student ID    : 104433206
//  Student Email : edgarciat-torres@myseneca.ca
//  Course Section: ZZA
// ===================================================================================

#ifndef ACCOUNT_H_
#define ACCOUNT_H_


struct Demographic {
	int birthYear;
	double inccome;
	char country[150];
	};

struct UserLogin {
	char name[150];
	char user[150];
	char password[150];
	};
//
struct Account {
	int accountNum;
	char acType;
	struct UserLogin loggin;
	struct Demographic Demo;
};


void getAccount(struct Account* database, struct Account account[], int max);

void getUserLogin(struct Account* login); //Recieves a modifiable UserLogin pointer argument

void getuser(struct Account* login);

void getpassword(struct Account* login);

void getDemographic(struct Account* demo); //Recieves a modifiable pointer argument

void getCountry(struct Account* demo);

void archiveremovedAccount(struct Account* account, int remove);

void recreateAccountsfileagent(struct Account* accounts, int size);

// Header file contents goes here...
#endif // 