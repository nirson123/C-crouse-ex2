#include <stdio.h>
#include "myBank.h"


//define the 2-D array representing the bank
double bank[2][50] = { 0 };

//open new acuunt
void open(double amount) {
	//make sure amount deposited is >=0
	if (amount < 0) {
		printf("can not deposite negative amount\n");
	}
	else {
		//find empty acuunt
		int i = 0;
		while (i < 50 && bank[1][i] != 0){i++;}
		//if the bank has no room, print error massege
		if (i == 50) {
			printf("all acuunts are taken\n");
		}
		//if the bank has room, open new acuunt with the amount given
		else {
			bank[0][i] = amount;
			bank[1][i] = 1;
			printf("%d\n", i + 900 + 1);
		}
	}
}

//print the balance
void balance(int acuunt_number) {
	//make sure the acuunt number is valid
	if (acuunt_number > 950 || acuunt_number < 901) {
		printf("not a valid acuunt number\n");
	}
	//make sure the acuunt is open
	else if(bank[1][acuunt_number - 900 - 1] == 0){
		printf("acuunt is not open\n");
	}
	//print the balance
	else {
		printf("%.2lf\n", bank[0][acuunt_number - 900 - 1]);
	}
}

//deposite to the given acuunt
void deposite(int acuunt_number, double amount) {
	//make sure the acuunt number is valid
	if (acuunt_number > 950 || acuunt_number < 901) {
		printf("not a valid acuunt number\n");
	}
	//make sure the acuunt is open
	else if (bank[1][acuunt_number - 900 - 1] == 0) {
		printf("acuunt is not open\n");
	}
	//make sure the amout is >=0
	else if(amount < 0) {
		printf("can not deposite negative amount\n");
	}
	//if everything is valid, deposite
	else {
		bank[0][acuunt_number - 900 - 1] += amount;
		printf("%.2lf\n", bank[0][acuunt_number - 900 - 1]);
	}
}

//withdraw the given amount from the given acuunt
void withdraw(int acuunt_number, double amount) {
	//make sure the acuunt number is valid
	if (acuunt_number > 950 || acuunt_number < 901) {
		printf("not a valid acuunt number\n");
	}
	//make sure the acuunt is open
	else if (bank[1][acuunt_number - 900 - 1] == 0) {
		printf("acuunt is not open\n");
	}
	//make sure the amout is >=0
	else if (amount < 0) {
		printf("can not withdraw negative amount\n");
	}
	//make sure the acuunt has enough cash
	else if (bank[0][acuunt_number - 900 - 1] < amount) {
		printf("not enough cash\n");
	}
	//if everything is valid, withdraw from the acuunt
	else {
		bank[0][acuunt_number - 900 - 1] -= amount;
		printf("%.2lf\n", bank[0][acuunt_number - 900 - 1]);
	}

}

//close the given acuunt
void close(int acuunt_number) {
	//make sure the acuunt number is valid
	if (acuunt_number > 950 || acuunt_number < 901) {
		printf("not a valid acuunt number\n");
	}
	//make sure the acuunt is open
	else if (bank[1][acuunt_number - 900 - 1] == 0) {
		printf("acuunt is not open\n");
	}
	//if everything is valid, close the acuunt
	else {
		bank[1][acuunt_number - 900 - 1] = 0;
	}
}

//add the given interest to all acuunts in the bank
void interest(double interest_rate) {
	//make sure the interest rate is >=0
	if (interest_rate < 0) {
		printf("can not add negative interest\n");
	}
	//add the interest to all open acunnts
	else {
		int i;
		for (i = 0; i < 50; i++) {
			if (bank[1][i] != 0) {	//if the acuunt is open, add the interest
				bank[0][i] *= (1 + (interest_rate / 100));
			}
		}
	}
}

//print all the open acuunts
void print() {
	int i;
	for (i = 0; i < 50; i++) {	//go through the acuunts
		if (bank[1][i] != 0) {	//if the acuunt is open, print it
			printf("acuunt number : %d balance : %.2lf \n" , (i + 900 + 1) , bank[0][i]);
		}
	}
}

//close all acuunts and end the program
void end() {
	//go thruogh all the acuunt and close them
	int i;
	for (i = 0; i < 50; i++) {
		bank[1][i] = 0;
	}
}


