#include <stdio.h>
#include "myBank.h"

int main() {
	char Transaction = 'a'; //initiate with temperery char
	double input1;
	int input2;
	while (Transaction != 'E') {
		printf("Transaction type? ");	//get the wanted trensaction
		scanf(" %c", &Transaction);		
		
		switch (Transaction)	//call the maching fuction
		{
		case 'O': 
			printf("Initial deposit?: ");
			scanf("%lf", &input1);
			open(input1);
			break;
		case 'B':
			printf("Account number?: ");
			scanf("%d", &input2);
			balance(input2);
			break;
		case 'D':
			printf("Account number?: ");
			scanf("%d", &input2);
			printf("amount ?: ");
			scanf("%lf", &input1);
			deposite(input2, input1);
			break;
		case 'W':
			printf("Account number?: ");
			scanf("%d", &input2);
			printf("amount ?: ");
			scanf("%lf", &input1);
			withdraw(input2, input1);
			break;
		case 'C':
			printf("Account number?: ");
			scanf("%d", &input2);
			close(input2);
			break;
		case 'I':
			printf("Interest rate?: ");
			scanf("%lf", &input1);
			interest(input1);
			break;
		case 'P':
			print();
			break;
		case 'E':
			end();
			break;
		default:
			printf("not a valid transaction\n");
			break;
		}

	}
	return 0;
}