#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#define MAX 5

typedef struct
{
  int cars[MAX];
  int tos;
} STACK;

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

int main(void)
{
  int num, i, car, checkCar;
  bool empty, full, found = false;
  char choice;
  STACK stack, temp;
  stack.tos = createStack();

  do
  {
    system("cls");
    choice = showMenuOptions();
    if (choice == 'A' || choice == 'a')
    {
      num = inputLicenseNum();
      full = isFull(stack.tos);
      if (!full)
      {
        push(&stack, num);
        printf("\n\tSuccess : car successfully parked...");
        getch();
      }
      else
      {
        printf("\n\tError : The garage is full please try some other time...");
        getch();
      }
      printf("\n\tPassed");
    }
    else if (choice == 'B' || choice == 'b')
    {
      printf("\n\tCHECK : %d", stack.tos);
      empty = isEmpty(stack.tos);
      if (empty)
      {
        printf("\n\tError : The garage is empty...");
      }
      else
      {
        num = inputLicenseNum();
        empty = isEmpty(stack.tos);
        while (!empty)
        {
          checkCar = pop(&stack);
          if (checkCar == num)
          {
            found = true;
            continue;
          }
          push(&temp, checkCar);
          empty = isEmpty(stack.tos);
        }

        full = isFull(stack.tos);
        while (!full)
        {
          car = pop(&temp);
          push(&stack, car);
        }

        if (!found)
        {
          printf("\n\tError : car is not in the garage...");
        }
        else
        {
          printf("\n\tSuccess : car was successfully removed from the garage...");
        }
      }
      printf("\n\tPassed");
      getch();
    }
    else if (choice == 'C' || choice == 'c')
    {
      displayCars(&stack);
      getch();
      printf("\n\tPassed");
    }
    else if (choice == 'D' || choice == 'd')
    {
      printf("\n\tEnd of Program");
      printf("\n\tPassed");
      break;
    }
    else
    {
      printf("\n\tError : choice does not exist, please try again...");
      continue;
    }
  } while (choice != 'D' || choice != 'd');
  return 0;
}

void displayCars(STACK *stack)
{
  int i, size = stack->tos + 1;
  bool empty;

  empty = isEmpty(stack->tos);
  if (!empty)
  {
    printf("\n\tLoaded : Cars in the Garage currently...");
    for (i = 0; i < size; i++)
    {
      printf("\n\t[%d] : %d", i, stack->cars[i]);
    }
    printf("\n");
  }
  else
  {
    printf("\n\tError : the garage is empty...");
  }
  return;
}

char showMenuOptions(void)
{
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

int inputLicenseNum()
{
  int num;

  do
  {
    printf("\n\n\tInput your license number : ");
    scanf("%d", &num);
    if (num < 100 || num > 999)
    {
      printf("\n\tError : license number must not be less than 100 or not greater 999...");
      continue;
    }
    else
    {
      break;
    }
  } while (1);
  return num;
}

int createStack(void)
{
  int tos = -1;
  return tos;
}

bool isEmpty(int tos)
{
  bool empty = false;
  if (tos == -1)
  {
    empty = true;
  }
  //	if(empty) {
  //		printf("\n\tIt is empty...");
  //	} else {
  //		printf("\n\tIt is not empty..");
  //	}
  return empty;
}

bool isFull(int tos)
{
  bool full = false;
  if (tos == (MAX - 1))
  {
    full = true;
  }
  return full;
}

void push(STACK *stack, int num)
{
  stack->tos += 1;
  stack->cars[stack->tos] = num;
  return;
}

int pop(STACK *stack)
{
  int num = stack->cars[stack->tos];
  stack->tos -= 1;
  return num;
}
