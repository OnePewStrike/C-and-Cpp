// Computing Problem 6b: Manipulating an Array of Structures

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define ITEM_SIZE 50
#define COMPANY_SIZE 30
#define TYPE_SIZE 25

typedef struct stackNode *ndptr;
struct stackNode
{
  char itemName[ITEM_SIZE];
  char companyName[COMPANY_SIZE];
  char itemType[TYPE_SIZE];
  float sellingPrice;
  int itemQty;
  ndptr next;
} RECORDS;

ndptr createStack(void);
int showMenuOptions(void);
void addNewItem(ndptr *);
void displayRecords(ndptr *);
void itemUpdate(ndptr *);
void itemDelete(ndptr *);
void typeFilterDisp(ndptr *);
void companyFilterDisp(ndptr *);
void gotoxy(short, short);

int main(void)
{
  int choice;
  ndptr tos = createStack();

  do
  {
    system("cls");
    choice = showMenuOptions();

    switch (choice)
    {
    case 1:
      addNewItem(&tos);
      break;
    case 2:
      itemUpdate(&tos);
      break;
    case 3:
      itemDelete(&tos);
      break;
    case 4:
      typeFilterDisp(&tos);
      break;
    case 5:
      companyFilterDisp(&tos);
      getch();
      break;
    case 6:
      displayRecords(&tos);
      break;
    case 7:
      break;
    default:
      printf("\n\tError: choice does not exist... Please try again.");
      getch();
      continue;
    }
  } while (choice != 7);
  printf("\n\tEnd of program");
  return;
}

void gotoxy(short x, short y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void companyFilterDisp(ndptr *tos)
{
  bool itemExist = false;
  char searchKey[TYPE_SIZE];
  ndptr temp = *tos;
  int count = 0, x = 5, y = 3;

  printf("\n\tFilter by company name from records..."
         "\n\tEnter company name: ");
  scanf("%s", &searchKey);

  if (temp == NULL)
  {
    printf("\n\tError: The are no item records...");
  }
  else
  {
    system("cls");
    gotoxy(x, y);
    printf("Displaying items by company name: %s", searchKey);
    while (temp != NULL)
    {
      if (strcmp(searchKey, temp->companyName) == 0)
      {
        itemExist = true;
        gotoxy(x, y + 1);
        printf("-------------------------");
        gotoxy(x, y + 2);
        printf("Item name: %s\t", temp->itemName);
        gotoxy(x, y + 3);
        printf("Company name: %s\t", temp->companyName);
        gotoxy(x, y + 4);
        printf("Item type: %s\t", temp->itemType);
        gotoxy(x, y + 5);
        printf("Item selling price: %.2f\t", temp->sellingPrice);
        gotoxy(x, y + 6);
        printf("Item quantity: %d\t", temp->itemQty);
        gotoxy(x, y + 7);
        printf("-----------------------");
        gotoxy(x, y + 8);
        printf("[%d]", count++);
        if (count % 4 == 0)
        {
          x = 5;
          y += 9;
          printf("\n");
        }
        else
        {
          x += 30;
        }
      }
      temp = temp->next;
    }
    if (!itemExist)
    {
      printf("\n\tError: The item does not exist in the records...");
      getch();
    }
    else
    {
      gotoxy(5, y + 10);
      printf("Press enter to continue...");
      getch();
    }
  }
}

void typeFilterDisp(ndptr *tos)
{
  bool itemExist = false;
  char searchKey[ITEM_SIZE];
  ndptr temp = *tos;
  int count = 0, x = 5, y = 3;

  printf("\n\tFilter by item type from records..."
         "\n\tEnter item type: ");
  scanf("%s", &searchKey);

  if (temp == NULL)
  {
    printf("\n\tError: The are no item records...");
  }
  else
  {
    system("cls");
    gotoxy(x, y);
    printf("Displaying items by item type: %s", searchKey);
    while (temp != NULL)
    {
      if (strcmp(searchKey, temp->itemType) == 0)
      {
        itemExist = true;
        gotoxy(x, y + 1);
        printf("-------------------------");
        gotoxy(x, y + 2);
        printf("Item name: %s\t", temp->itemName);
        gotoxy(x, y + 3);
        printf("Company name: %s\t", temp->companyName);
        gotoxy(x, y + 4);
        printf("Item type: %s\t", temp->itemType);
        gotoxy(x, y + 5);
        printf("Item selling price: %.2f\t", temp->sellingPrice);
        gotoxy(x, y + 6);
        printf("Item quantity: %d\t", temp->itemQty);
        gotoxy(x, y + 7);
        printf("-----------------------");
        gotoxy(x, y + 8);
        printf("[%d]", count++);

        if (count % 4 == 0)
        {
          x = 5;
          y += 9;
          printf("\n");
        }
        else
        {
          x += 30;
        }
      }
      temp = temp->next;
    }
    if (!itemExist)
    {
      printf("\n\tError: The item does not exist in the records...");
      getch();
    }
    else
    {
      gotoxy(5, y + 10);
      printf("Press enter to continue...");
      getch();
    }
  }
}

void itemDelete(ndptr *tos)
{
  bool itemExist = false;
  char searchKey[ITEM_SIZE];
  ndptr temp = *tos, prev;

  printf("\n\tSearch item name from records..."
         "\n\tEnter item name: ");
  scanf("%s", &searchKey);

  if (temp == NULL)
  {
    printf("\n\tError: There are no item records...");
    getch();
  }
  else
  {
    while (temp != NULL)
    {
      if (strcmp(searchKey, temp->itemName) == 0)
      {
        itemExist = true;
        break;
      }
      prev = temp;
      temp = temp->next;
    }

    if (itemExist)
    {
      if (prev != NULL)
      {
        prev->next = temp->next;
      }
      else
      {
        *tos = temp->next;
      }
      printf("\n\tSuccess: The item was succesfully deleted...");
      getch();
    }
    else
    {
      printf("\tError: The item does not exist in the records...");
      getch();
    }
  }
}

void itemUpdate(ndptr *tos)
{
  bool itemExist = false;
  char searchKey[ITEM_SIZE];
  float sellingPrice;
  int itemQty, count = 0, x = 5, y = 3, index = 0, choice;
  ndptr temp = *tos, head = *tos, copy;

  printf("\n\tSearch item name from records..."
         "\n\tEnter item name: ");
  scanf("%s", &searchKey);

  if (temp == NULL)
  {
    printf("\n\tError: There are no item records...");
  }
  else
  {
    system("cls");
    gotoxy(x, y);
    printf("\n\tEditing item from records...");
    while (temp != NULL)
    {
      if (strcmp(searchKey, temp->itemName) == 0)
      {
        itemExist = true;
        gotoxy(x, y + 2);
        printf("-------------------------");
        gotoxy(x, y + 3);
        printf("Item name: %s\t", temp->itemName);
        gotoxy(x, y + 4);
        printf("Company name: %s\t", temp->companyName);
        gotoxy(x, y + 5);
        printf("Item type: %s\t", temp->itemType);
        gotoxy(x, y + 6);
        printf("Item selling price: %.2f\t", temp->sellingPrice);
        gotoxy(x, y + 7);
        printf("Item quantity: %d\t", temp->itemQty);
        gotoxy(x, y + 8);
        printf("-----------------------");
        gotoxy(x, y + 9);
        printf("[%d]", count++);

        if (count % 4 == 0)
        {
          x = 5;
          y += 9;
          printf("\n");
        }
        else
        {
          x += 30;
        }
      }
      temp = temp->next;
    }

    if (count > 1)
    {
      printf("\n\n\tPlease choose which [index] you want to update: ");
      scanf("%d", &choice);
      index = 0;
      temp = head;
      while (temp != NULL)
      {
        if (strcmp(searchKey, temp->itemName) == 0)
        {
          if (index == choice)
          {
            break;
          }
          index++;
        }
        temp = temp->next;
      }
    }
    else if (count == 1)
    {
      temp = head;
      while (temp != NULL)
      {
        if (strcmp(searchKey, temp->itemName) == 0)
        {
          break;
        }
        temp = temp->next;
      }
    }
    else
    {
      printf("\tError: The item does not exist in the records...");
      getch();
      return;
    }
    printf("\n\tItem found: %s", temp->itemName);
    printf("\n\tEnter new selling price: ");
    scanf("%f", &sellingPrice);
    printf("\tEnter new item quantity: ");
    scanf("%d", &itemQty);
    temp->sellingPrice = sellingPrice;
    temp->itemQty = itemQty;
    printf("\tSuccess: The item was updated successfully...");
    getch();
  }
}

void displayRecords(ndptr *tos)
{
  ndptr head = *tos, ptr;
  int count = 0, x = 5, y = 3;

  if (head == NULL)
  {
    printf("\n\tError: There are no records found...");
  }
  else
  {
    ptr = head;
    system("cls");
    gotoxy(x, y);
    printf("Displaying all items in the records...");
    while (ptr != NULL)
    {
      gotoxy(x, y + 1);
      printf("-------------------------");
      gotoxy(x, y + 2);
      printf("Item name: %s\t", ptr->itemName);
      gotoxy(x, y + 3);
      printf("Company name: %s\t", ptr->companyName);
      gotoxy(x, y + 4);
      printf("Item type: %s\t", ptr->itemType);
      gotoxy(x, y + 5);
      printf("Item selling price: %.2f\t", ptr->sellingPrice);
      gotoxy(x, y + 6);
      printf("Item quantity: %d\t", ptr->itemQty);
      gotoxy(x, y + 7);
      printf("-----------------------");
      gotoxy(x, y + 8);
      printf("[%d]", count++);
      ptr = ptr->next;

      if (count % 4 == 0)
      {
        x = 5;
        y += 9;
        printf("\n");
      }
      else
      {
        x += 30;
      }
    }
  }
  printf("\n\n\tPress enter to continue...");
  getch();
  return;
}

void addNewItem(ndptr *tos)
{
  ndptr temp = malloc(sizeof(RECORDS));
  printf("\n\tAdding new item record..."
         "\n\tPlease enter item name: ");
  scanf("%s", &temp->itemName);
  printf("\tPlease enter the company name: ");
  scanf("%s", &temp->companyName);
  printf("\tPlease enter item type: ");
  scanf("%s", &temp->itemType);
  printf("\tPlease enter selling price: ");
  scanf("%f", &temp->sellingPrice);
  printf("\tPlease enter item quantity: ");
  scanf("%d", &temp->itemQty);

  temp->next = *tos;
  *tos = temp;
  printf("\n\tItem is added to the records successfully...");
  getch();
  return;
}

ndptr createStack(void)
{
  ndptr temp = NULL;
  return temp;
}

int showMenuOptions(void)
{
  int input;
  printf("\n\tBarba's Online Store"
         "\n\t1.Add new item"
         "\n\t2.Search and edit"
         "\n\t3.Search and delete"
         "\n\t4.Search and filter (item type)"
         "\n\t5.Search and filter (item company)"
         "\n\t6.Display all records"
         "\n\t7.Exit"
         "\n\tEnter choice: ");
  scanf("%d", &input);
  return input;
}
