#ifndef MYBANK
#define MYBANK

#define number_of_accunts 50
#define lowest_accunt_number 901
#define highest_accunt_number 950


//open new acuunt
void open(double amount, double bank[2][number_of_accunts]);

//print the balance
void balance(int acuunt_number, double bank[2][number_of_accunts]);

//deposite to the given scuunt
void deposite(int acuunt_number, double amount, double bank[2][number_of_accunts]);

//withdraw the given amount from the given acuunt
void withdraw(int acuunt_number, double amount, double bank[2][number_of_accunts]);

//close the given acuunt
void close(int acuunt_number, double bank[2][number_of_accunts]);

//add the given interest to all acuunts in the bank
void interest(int interest_rate, double bank[2][number_of_accunts]);

//print all the open acuunts
void print(double bank[2][number_of_accunts]);

//close all acuunts and end the program
void end(double bank[2][number_of_accunts]);

#endif // !MYBANK

