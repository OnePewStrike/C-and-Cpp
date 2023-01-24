#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#define MAX 5

typedef struct {
	int cars[MAX];
	int tos;
}STACK;

bool findDuplicate(STACK *, int);
char showMenuOptions(void);
int inputLicenseNum();
int createStack(void);
bool isEmpty(int);
bool isFull(int);
void push(STACK *, int);
int pop(STACK *);
void parkNewCar(int);
void pickUpCar();
void displayCars(STACK *);

int main (void) {
	int num, i, car, checkCar, foundCar, size;
	bool empty, full, found = false, isDuplicate;
	char choice;
	STACK stack, temp;
	stack.tos = createStack();
	
	do {
		system("cls");
		choice = showMenuOptions();
		if(choice == 'A' || choice == 'a') {
			num = inputLicenseNum();
			isDuplicate = findDuplicate(&stack, num);
			if (!isDuplicate) {
				full = isFull(stack.tos);
				if(!full) {
					push(&stack, num);
					printf("\n\tSuccess : car successfully parked...");
					getch();
				} else {
					printf("\n\tError : The garage is full please try some other time...");
					getch();
				}	
			} else {
				printf("\n\tError : There exists a duplicate plate number in the garage...");
				getch();
			}
		} else if (choice == 'B' || choice == 'b') {
			empty = isEmpty(stack.tos);
			if(!empty) {
				num = inputLicenseNum();
				empty = isEmpty(stack.tos);
				while(!empty) {
					checkCar = pop(&stack);
					if (checkCar == num) {
						foundCar = pop(&stack);
						stack.tos++;
						found = true;
					} else {
						push(&temp, checkCar);	
						size++;
					}
					empty = isEmpty(stack.tos);
				};
				
				displayCars(&temp);
				getch();
				
				for(i = 0; i < size; i++) {
					car = pop(&temp);
					push(&stack, car);
				}
				
				displayCars(&stack);
				getch();
				
				if (!found) {
					printf("\n\tError : car is not in the garage...");
				} else {
					printf("\n\tSuccess : car was successfully removed from the garage...");
				}
				
			} else {
				printf("\n\tError : The garage is empty...");
			}	
			getch();
		} else if (choice == 'C' || choice == 'c') {
			displayCars(&stack);
			getch();
		} else if (choice == 'D' || choice == 'd') {
			printf("\n\tEnd of Program");
			break;
		} else {
			printf("\n\tError : choice does not exist, please try again...");
			continue;	
		}
	} while (choice != 'D' || choice != 'd');
	return 0;
}

bool findDuplicate(STACK *stack, int num) {
	STACK temp = *stack;
	int size = temp.tos, i;
	bool isDuplicate = false;
	
	for(i=0; i<size; i++) {
		if (num == temp.cars[i]) {
			isDuplicate = true;
		}
	}
	return isDuplicate;
}

void displayCars(STACK *stack) {
	int i, size = stack->tos + 1;
	bool empty;
	
	empty = isEmpty(stack->tos);
	if (!empty) {
		printf("\n\tLoaded : Cars in the garge currently...");
		for (i=0; i < size; i++) {
			printf("\n\t[%d] : %d", i, stack->cars[i]);
		}	
		printf("\n");
	} else {
		printf("\n\tError : the garage is empty...");
	}
	return;
}

char showMenuOptions(void) {
	char choice;
	printf("\n\tMain Menu");
	printf("\n\tA. Park a Car");
	printf("\n\tB. Pick up a Car");
	printf("\n\tC. Display all Cars");
	printf("\n\tD. Exit Program");
	printf("\n\tUser choice : ");
	scanf("\n%c", &choice);
	return choice;
}

int inputLicenseNum() {
	int num;
	
	do {
		printf("\n\n\tInput your license number : ");
		scanf("%d", &num);
		if (num < 100 || num > 999) {
			printf("\n\tError : license number must not be less than 100 or not greater 999...");
			continue;
		} else {
			break;
		}
	} while (1);
	return num;
}

int createStack(void) {
	int tos = -1;
	return tos;
}

bool isEmpty(int tos) {
	bool empty = false;
	if (tos == -1) {
		empty = true;
	}
	return empty;
}

bool isFull(int tos) {
	bool full = false;
	if (tos == (MAX-1)) {
		full = true;
	}
	return full;
}

void push(STACK *stack, int num) {
	stack->tos +=1;
	stack->cars[stack->tos] = num;
	return;
}

int pop(STACK *stack) {
	int num = stack->cars[stack->tos--];
	return num;
}

