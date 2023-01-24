// AIRPORT SIMULATION
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define queueSize 6
#define landingTime 4
#define takeOffTime 6
#define landingRate 8
#define takeOffRate 6

typedef struct
{
  int randVal[queueSize];
  int front;
  int rear;
} QUEUE;

QUEUE createCQueue(void);
bool isEmpty(int, int);
bool isFull(int, int);
void enCQueue(QUEUE *, int);
int deCQueue(QUEUE *);
// void airportSimulation(void);
void genRandNum(int *, int *);
bool flightCondition(int, int);
void clearRunway(void);
float calculateMins(float num, int timer);
float calculateLanding(int, int);
float calculateTakeOff(int, int);

int main(void)
{ // airport simulation
  int firstRand = 0, secondRand = 0;
  int timer = 5;
  bool empty, full;

  QUEUE landingQue, takeOffQue;
  // two queues for planes that want to land and planes that want to take off
  landingQue = createCQueue();
  takeOffQue = createCQueue();

  // Initialize two landing queues
  genRandNum(&firstRand, &secondRand);
  enCQueue(&landingQue, firstRand);
  genRandNum(&firstRand, &secondRand);
  enCQueue(&landingQue, firstRand);

  // to simulate landing and take off, if landing queue is not empty prioritize it first before take off,
  // allow delay: runway clearing for 5 seconds for both landing and take off,
  // generation of random number to firstRand and secondRand,
  // generated value determines if landing arrival occurred or take off occurred,
  // check if full for both landing and take off if so decline request/not add to queue to land or take off,

  do
  {
    clearRunway();
    empty = isEmpty(landingQue.front, landingQue.rear);
    if (!empty)
    { // priority landing queue
      printf("\n\tA plane has landed...");
      printf("\n\tLanding Time (mins): %.2f", calculateMins(firstRand, timer));
      deCQueue(&landingQue);
    }
    else
    {
      printf("\n\tA plane has took off...");
      printf("\n\tTake Off Time (mins): %.2f", calculateMins(secondRand, timer));
      deCQueue(&takeOffQue);
    }
    printf("\n");
    genRandNum(&firstRand, &secondRand);
    // printf("\n\tGENERATION CHECK -- firstRand: %d secondRand: %d", firstRand, secondRand);
    if (flightCondition(firstRand, secondRand))
    {
      full = isFull(landingQue.front, landingQue.rear);
      if (!full)
      {
        printf("\n\tA plane wants to land...added to queue");
        enCQueue(&landingQue, firstRand);
        printf("\n\tPlane: %d", firstRand);
      }
      else
      {
        printf("\n\tA plane wanting to land is declined... queue is full");
      }
    }
    else
    {
      full = isFull(takeOffQue.front, takeOffQue.rear);
      if (!full)
      {
        printf("\n\tA plane wants to take off... added to queue...");
        enCQueue(&takeOffQue, secondRand);
        printf("\n\tPlane: %d", secondRand);
      }
      else
      {
        printf("\n\tA plane wanting to take off is declined... queue is full");
      }
    }
    // printf("\n\n\tContinue? (space to stop): ");
    // } while(getch() != ' ');
  } while (1);
  printf("\nEnd of program");
  return 0;
}

QUEUE createCQueue(void)
{
  int i;
  QUEUE q;
  for (i = 0; i < queueSize; i++)
  {
    q.randVal[i] = 0;
  }
  q.rear = 0;
  q.front = 0;
}

bool isEmpty(int front, int rear)
{
  bool empty = false;
  if (front == rear)
  {
    empty = true;
  }
  return empty;
}

bool isFull(int front, int rear)
{
  bool full = false;
  if (front == ((rear + 1) % queueSize))
  {
    full = true;
  }
  return full;
}

void enCQueue(QUEUE *que, int data)
{
  que->randVal[que->rear] = data;
  que->rear = (que->rear + 1) % queueSize;
  return;
}

int deCQueue(QUEUE *que)
{
  int val;
  val = que->randVal[que->front];
  que->front = (que->front + 1) % queueSize;
  return val;
}
/*
void airportSimulation(void) {

}
*/
void genRandNum(int *firstNum, int *secondNum)
{
  // generate num 0 to 500
  *firstNum = rand() % 501;
  *secondNum = rand() % 501;
  // printf("\n\nCHECK RAND:\nfirstRand: %d\nsecondRand: %d\n", *firstRand, *secondRand);
  return;
}

bool flightCondition(int firstRand, int secondRand)
{
  bool condition;
  if ((firstRand / 60) < landingRate && (secondRand / 60) < takeOffRate)
  {
    // landing arrival occurred
    condition = true;
  }
  else
  {
    // take off occurred
    condition = false;
  }
  return condition;
}

float calculateMins(float num, int timer)
{
  // print landingTime (mins)
  // print takeOffTime (mins)
  num = (num + timer) / 60;
  return num;
}

void clearRunway(void)
{
  int i, timer = 5;
  for (i = timer; i >= 0; i--)
  {
    // system("cls");
    printf("\n\tThe runway is clearing... %d", timer--);
    sleep(1);
  }
  printf("\n\tThe runway is cleared...");
  return;
}