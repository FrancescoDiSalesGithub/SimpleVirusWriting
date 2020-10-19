
#include<stdio.h>
#include<stdlib.h>

#define fourGB 4000000000

//warning: this piece of code will damage your ssd with a lot of runs

int main()
{
 

 long int i=0;
 printf("wait.... \n");
 FILE* bombFile=fopen("miofile.txt","w");


  for(i=0;i<4000000000;i++)
   fprintf(bombFile,"a");
 
 
 fclose(bombFile);


 return 0;
}
