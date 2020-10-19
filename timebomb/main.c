#include<time.h>
#include<stdio.h>

int main()
{

  struct tm* timer;
  time_t timex;

  time(&timex);
  timer = localtime(&timex);

  printf("%d %d \n",timer->tm_mday,timer->tm_mon);
  printf("Current local time and date: %s", asctime(timer));

  if(timer->tm_mday == 19 && timer->tm_mon==9)
    printf("bomb executed goodbye \n");

   return 0;

}
