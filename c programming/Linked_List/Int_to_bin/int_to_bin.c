// -- -- -- -- -- -- -- -- -- --CONVERT INT TO BIN LINKED LIST-- -- -- -- -- -- -- -- -- --
// integer to binary conversion - stack linked-list implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode *ndPtr;
struct stackNode
{
  int binNum;
  ndPtr next;
} STACKNODE;

void inputInteger(int *);
ndPtr createStack(void);
bool isEmpty(ndPtr);
void push(ndPtr *, int);
int pop(ndPtr *);
void convertIntBin(int);
void displayBinary(int);

int main(void)
{
  int intNum;
  inputInteger(&intNum);
  convertIntBin(intNum);
  return;
}

void inputInteger(int *num)
{
  printf("\n\n\tInput an integer value: ");
  scanf("%d", num);
  return;
}

ndPtr createStack(void)
{
  ndPtr temp = NULL;
  return temp;
}

bool isEmpty(ndPtr tos)
{
  bool empty = false;
  if (tos == NULL)
    empty = true;
  return empty;
}

void push(ndPtr *tos, int binNum)
{
  ndPtr temp = malloc(sizeof(STACKNODE));
  temp->binNum = binNum;
  temp->next = *tos;
  *tos = temp;
  return;
}

int pop(ndPtr *tos)
{
  int binReturn = (*tos)->binNum;
  ndPtr temp = *tos;
  *tos = (*tos)->next; // *tos = temp->next;
  free(temp);
  return binReturn;
}

void displayBinary(int binNum)
{
  printf("%d", binNum);
}

void convertIntBin(int intNum)
{
  int rem, binNum, num = intNum;
  bool empty;
  ndPtr tos = createStack();

  while (num != 0)
  {
    rem = num % 2;
    push(&tos, rem);
    num = num / 2;
  }
  empty = isEmpty(tos);
  printf("\n\n\t%d = ", intNum);
  if (intNum == 0)
    printf("0");
  else
  {
    while (!empty) // while(!empty)
    {
      binNum = pop(&tos);
      displayBinary(binNum);
      empty = isEmpty(tos);
    }
  }

  getch();
}