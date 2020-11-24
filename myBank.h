#ifndef MYBANK
#define MYBANK

//open new acuunt
void open(double amount);

//print the balance
void balance(int acuunt_number);

//deposite to the given scuunt
void deposite(int acuunt_number, double amount);

//withdraw the given amount from the given acuunt
void withdraw(int acuunt_number, double amount);

//close the given acuunt
void close(int acuunt_number);

//add the given interest to all acuunts in the bank
void interest(double interest_rate);

//print all the open acuunts
void print();

//close all acuunts and end the program
void end();

#endif // !MYBANK

