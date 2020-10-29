#include<stdio.h>
#include<string.h>

#define MAXLEN 999999

int main(int argc,char* argv[])
{

 FILE* hosts=fopen("/etc/hosts","r");
 FILE* newHosts=fopen("/etc/hosts2","w");

 char content[MAXLEN];
 int contentLine,line=0;

 while(fgets(content,MAXLEN,hosts))
 {

	 if(strstr(content,argv[1]))
	    contentLine=line;

	 line++;

 }

 fclose(hosts);
 hosts=fopen("/etc/hosts","r");
 line=0;

 while(fgets(content,MAXLEN,hosts)!=NULL && line<contentLine)
 {
	fprintf(newHosts,"%s",content);
	line++;
 }
 
 fclose(hosts);
 fclose(newHosts);

 remove("/etc/hosts");
 rename("/etc/hosts2","/etc/hosts");
 return 0;

}
