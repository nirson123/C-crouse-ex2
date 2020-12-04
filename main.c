#include <stdio.h>
#include "myBank.h"


int main() {
	double bank[2][number_of_accunts] = { 0 };
	int open_accunts = 0;
	int int_input;
	double double_input;
	char transaction = ' ';

	while (transaction != 'E') {
		printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
		scanf(" %c", &transaction);

		switch (transaction)
		{

		case 'O':
			//make sure the bank is not full
			if (open_accunts == number_of_accunts) {
				printf("the bank is full\n");
			}
			//get input
			printf("Please enter amount for deposit: ");
			if (scanf("%lf", &double_input) == 0) {
				printf("Failed to read the amount\n");
			}
			//make sure amount is not negative
			else if (double_input < 0) {
				printf("Invalid amount\n");
			}
			//open
			else {
				open(double_input, bank);
				open_accunts++;
			}
			break;
		case 'B':
			//get input
			printf("Please enter account number: ");
			if (scanf("%d", &int_input) == 0) {
				printf("Failed to read the account number\n");
			}
			//make sure the accunt number is in range
			else if (int_input < lowest_accunt_number || int_input > highest_accunt_number) {
				printf("Invalid account number\n");
			}
			//make sure the accunt is open
			else if (bank[1][int_input - lowest_accunt_number] == 0) {
				printf("This account is closed\n");
			}
			else {
				balance(int_input , bank);
			}
			break;
		case 'D':
			//get input
			printf("Please enter account number: ");
			if (scanf("%d", &int_input) == 0) {
				printf("Failed to read the account number\n");
			}
			//make sure the accunt number is in range
			else if (int_input < lowest_accunt_number || int_input > highest_accunt_number) {
				printf("Invalid account number\n");
			}
			//make sure the accunt is open
			else if (bank[1][int_input - lowest_accunt_number] == 0) {
				printf("This account is closed\n");
			}
			//if the accunt number is valid
			else {
				//get input
				printf("Please enter the amount to deposit: ");
				if (scanf("%lf", &double_input) == 0) {
					printf("Failed to read the amount\n");
				}
				//make sure amount is not negative
				else if (double_input < 0) {
					printf("Cannot deposit a negative amount\n");
				}
				else {
					deposite(int_input, double_input , bank);
				}
			}
			break;
		case 'W':
			//get input
			printf("Please enter account number: ");
			if (scanf("%d", &int_input) == 0) {
				printf("Failed to read the account number\n");
			}
			//make sure the accunt number is in range
			else if (int_input < lowest_accunt_number || int_input > highest_accunt_number) {
				printf("Invalid account number\n");
			}
			//make sure the accunt is open
			else if (bank[1][int_input - lowest_accunt_number] == 0) {
				printf("This account is closed\n");
			}
			//if accunt number is valid
			else {
				//get input
				printf("Please enter the amount to withdraw: ");
				if (scanf("%lf", &double_input) == 0) {
					printf("Failed to read the amount\n");
				}
				//make sure enough money in accunt
				else if (bank[0][int_input - lowest_accunt_number] < double_input) {
					printf("Cannot withdraw more than the balance\n");
				}
				else {
					withdraw(int_input, double_input , bank);
				}
			}
			break;
		case 'C':
			//get input
			printf("Please enter account number: ");
			if (scanf("%d", &int_input) == 0) {
				printf("Failed to read the account number\n");
			}
			//make sure the accunt number is in range
			else if (int_input < lowest_accunt_number || int_input > highest_accunt_number) {
				printf("Invalid account number\n");
			}
			//make sure the accunt is open
			else if (bank[1][int_input - lowest_accunt_number] == 0) {
				printf("This account is already closed\n");
			}
			else {
				close(int_input , bank);
				open_accunts--;
			}
			break;
		case 'I':
			//get input
			printf("Please enter interest rate: ");
			if (scanf("%lf", &double_input) == 0) {
				printf("Failed to read the interest rate\n");
			}
			//make sure the unterest rate is not less then -99%
			else if (double_input < -99) {
				printf("Invalid interest rate\n");
			}
			else {
				interest(double_input , bank);
			}
			break;
		case 'P':
			print(bank);
			break;
		case 'E':
			end(bank);
			open_accunts = 0;
			break;
		default:
			printf("Invalid transaction type\n");
			break;
		}
	}
}

