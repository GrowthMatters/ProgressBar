#include <stdio.h>   //Includes standard input(scanf()) and Standard output (printf())
#include <windows.h> //Includes sleep function Sleep(ms) for windows and sleep(s) for linux
#include <time.h>    //for seeding srand(time(NULL)) the rand()function to generate random numbers
#include <stdlib.h>  //Includes system("cls") for windows and system("clear")for linux
// Constants used or which can differ
const int MAX_SIZE = 15;
const int BAR_LENGTH = 50;
// Creating a Structure containing Task:Id,progress,speed
typedef struct
{
  int Id;
  int progress;
  int speed;
} Task;
// Function Declaration:-
void print_bar(Task task);
void clear_screen();
int main()
{
  Task tasks[MAX_SIZE];
  srand(time(NULL)); // Seeding of rand() function to generate random values at every call.
  // Initializing taks with random values
  for (int i = 0; i < MAX_SIZE; i++)
  {
    tasks[i].Id = i + 1;
    tasks[i].progress = 0;
    tasks[i].speed = rand() % MAX_SIZE + 1; // genrates random number from 1 to 4 and add it to the tasks.
  }
  int tasks_incomplete = 1;
  while (tasks_incomplete)
  {
    tasks_incomplete = 0;
    clear_screen();
    for (int i = 0; i < MAX_SIZE; i++)
    {
      tasks[i].progress += tasks[i].speed;
      if (tasks[i].progress > 100)
      {
        tasks[i].progress = 100;
      }
      else if (tasks[i].progress < 100)
      {
        tasks_incomplete = 1;
      }
      print_bar(tasks[i]);
    }
    Sleep(1000); // Sleep for 1s
  }
  printf("\n All %d tasks 100%% Completed", MAX_SIZE);
  return 0;
}
void print_bar(Task task)
{
  int bars_to_show = (BAR_LENGTH * task.progress) / 100; // bars_to_show=(50*20)/100=10 for 20% progresss
  printf("Tasks %d : [", task.Id);                       // only once for every tasks[i]
  for (int i = 0; i < BAR_LENGTH; i++)
  {
    if (i < bars_to_show)
    {
      printf("=");
    }
    else
    {
      printf(" ");
    }
  }
  printf("] %d%% \n", task.progress);
}
void clear_screen()
{
#ifdef _WIN32
  system("cls");
// printf("Did it clear?\n");
#else
  system("clear");
#endif
}