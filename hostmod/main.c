#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>

#define MAX_LENGTH 999999

int main()
{

 char hosts_to[MAX_LENGTH];
 FILE* hosts=fopen("hostransfer.txt","r");
 
 if(hosts==NULL)
 {
   printf("file hostransfer.txt does not exist \n");
   exit(-1);
 }
 
 FILE* realHost = fopen("/etc/hosts","a");

 
 if(getuid()!=0)
 {
   printf("you must run this program as root... \n");
   exit(-1);
 }
 else
 if(realHost == NULL)
 {
   printf("[ALERT] - Somebody has removed the hosts file... \n");
   exit(-1);
 }

 while(fgets(hosts_to,MAX_LENGTH,hosts))
  fprintf(realHost,"%s",hosts_to);
 
 fclose(hosts);
 fclose(realHost);

 printf("hosts file modified \n");

 return 0;
}
