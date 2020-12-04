#include <stdio.h>
#include "myBank.h"

void open(double amount, double bank[2][number_of_accunts]) {
	//if the bank is not full
		int i = 0;	
		while (bank[1][i] != 0) {	//find empty accunt
			i++;
		}
		bank[1][i] = 1;			//open
		bank[0][i] = amount;	//deposite
		printf("New account number is: %d \n", i + lowest_accunt_number);
}

void balance(int accunt_number, double bank[2][number_of_accunts]) {
	//print the balance
	printf("The balance of account number %d is: %.2lf\n", accunt_number, bank[0][accunt_number - lowest_accunt_number]);
}

void deposite(int accunt_number, double amount, double bank[2][number_of_accunts]) {
	//deposite
	bank[0][accunt_number - lowest_accunt_number] += amount;
	//print the new balance
	printf("The new balance is: %.2lf\n", bank[0][accunt_number - lowest_accunt_number]);
}

void withdraw(int accunt_number, double amount, double bank[2][number_of_accunts]) {
	//withdraw the amount
	bank[0][accunt_number - lowest_accunt_number] -= amount;
	//print the new balance
	printf("The new balance is: %.2lf\n", bank[0][accunt_number - lowest_accunt_number]);
}

void close(int accunt_number, double bank[2][number_of_accunts]) {
	//close the accunt
	bank[1][accunt_number - lowest_accunt_number] = 1;
	printf("Closed account number %d\n", accunt_number);
}

void interest(int interest_rate, double bank[2][number_of_accunts]) {
	int i;
	for (i = 0; i < number_of_accunts; i++) {			//add the interest to all accunts
		bank[0][i] *= (1 + (interest_rate / 100.0));
	}
}

void print(double bank[2][number_of_accunts]) {
	int i;
	for (i = 0; i < number_of_accunts; i++) {		//print all open accunts
		if (bank[1][i] != 0) {
			printf("The balance of account number %d is: %.2lf\n",  i + lowest_accunt_number , bank[0][i]);
		}
	}
}

void end(double bank[2][number_of_accunts]) {
	int i;
	for (i = 0; i < number_of_accunts; i++) {		//close all accunts
		bank[1][i] = 0;
	}
}
