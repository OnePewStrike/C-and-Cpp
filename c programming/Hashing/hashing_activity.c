#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define S 5
#define K 7
#define LH 10
#define INCR 7
#define FLUSH while (getchar() != '\n')

typedef struct
{
  char personId[S];
  char personName[30];
} PERSON;

typedef struct
{
  PERSON person;
  char status;
} TABLE;

void createTable(TABLE[]);
PERSON inputData(void);
void insertData(TABLE[], PERSON);
int convertStringOption3(char[]);
int hashTruncation(int);
int doubleHashing(int, int);
bool searchData(TABLE[], int *, char[], PERSON *, int);
void deleteDAta(TABLE[], char[]);

int main(void)
{
  int choice, index, key;
  bool found, full;
  char chrKey[S];
  PERSON per;
  TABLE T[LH];
}

void createTable(TABLE T[])
{
  int i;

  for (i = 0; i < LH; i++)
  {
    strcpy(T[i].person.personId, "");
    strcpy(T[i].person.personName, "");
    strcpy(T->status, "Available");
  }
  return;
}

PERSON inputData(void)
{
  PERSON P;
  printf("\nAdding new person..."
         "\nPlease enter identification: ");
  gets(P.personId);
  printf("\nPlease enter name: ");
  gets(P.personName);
  return P;
}

int convertStringOption3(char chrKey[])
{
  int L = strlen(chrKey), key = 0, i;

  for (i = 0; i < L; i++)
  {
    key = key + (chrKey[L - i - 1] * pow(K, i));
  }
  return key;
}

int hashTruncation(int key)
{
  return (key % 10);
}

int doubleHashing(int index, int key)
{
  int increment;

  increment = 1 + (key % INCR);
  index = (index + increment) % LH;
  return index;
}

bool searchData(TABLE T[], int *index, char chrKey[], PERSON *per, int key)
{
  int P = *index, comp;
  bool found = false;

  while (!found)
  {
    if (T[P].status == 'o' || T[P].status == "d")
    {
      comp = strcmp(T[P].person.personId, chrKey);
      if (comp == 0)
      {
        if (T[P].status == 'o')
        {
          *per = T[P].person;
          *index = P;
          found = true;
        }
        else
        {
          // not found
          break;
        }
      }
      else
      {
        P = doublHashing(P, key);
        if (P == *index)
        {
          break;
        }
      }
    }
    else
    {
      break;
    }
  }
}

void deleteData(TABLE T[], char chrKey[])
{
  int index, key;
  bool found;
  PERSON per;
  key = convertStringOption3(chrKey);
  index = hashTruncation(key);
  found = searchData(T, &index, chrKey, &per, key);
  if (found)
  {
    displayData(per);
    printf("\nDo you want to delete data? (y/n) ");
    if (getch() == 'y')
    {
      T[index].status = 'd';
    }
  }
  else
  {
    printf("\nData not found...");
  }
  return;
}

void insertData(TABLE T[], PERSON per)
{
  int index, key, P;
  bool full = false;
  key = converStringOption3(per.personId);
  index = hashTruncation(key);

  P = index;
  while (!full)
  {
    if (T[P].status == 'e' || T[P].status == 'd')
    {
      T[P].person = per;
      T[P].status = 'o';
      break;
    }
    else
    {
      P = doubleHashing(P, key);
      if (P == index)
      {
        full = true;
        break;
      }
    }
  }
  return;
}