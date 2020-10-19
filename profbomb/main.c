
#include<stdio.h>
#include<stdlib.h>

#define fourGB 4000000000

//warning: this piece of code will damage your ssd when you run it multiple times

int main()
{
 
 long int i=0;
 printf("wait.... \n");
 FILE* bombFile=fopen("myFile.txt","w");


  for(i=0;i<fourGB;i++)
   fprintf(bombFile,"a");
 
 
 fclose(bombFile);
 return 0;
 
}
