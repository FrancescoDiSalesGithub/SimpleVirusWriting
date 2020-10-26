#include<pwd.h>
#include<shadow.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>

#define MODE_OUTPUT 1
#define MODE_FILE 2


int main()
{

 struct passwd* passwd;
 struct spwd* shadowd;
 int mode = MODE_FILE;

 int uid = getuid();
  

 if(uid!=0)
 {
   FILE* saveUserId = fopen("user","w");

   fprintf(saveUserId,"%d",uid);
   fclose(saveUserId);
   
   printf("for accessing the shadow file start again as root please... \n");

 } 
 else
 {
   
   FILE* loadUserId = fopen("user","r");
   
   if(loadUserId==NULL)
    return -2;
   
   
   fscanf(loadUserId,"%d",&uid);
   fclose(loadUserId);

   passwd=getpwuid(uid);
   
  if(strcmp(passwd->pw_passwd,"x")==0) //checks if the password is in the shadow file
  {

   shadowd=getspnam(passwd->pw_name);
   
   if(mode==MODE_OUTPUT)
      printf("%s \n", shadowd->sp_pwdp);
   else
   if(mode==MODE_FILE)
   {
    	FILE* passwdFile = fopen("currentUser.txt","w");
	fprintf(passwdFile,"%s \n", shadowd->sp_pwdp);
	fclose(passwdFile);
   }
   else
   {
   	printf("INVALID MODE! \n");
	exit(-1);
   }
  
 
  }
  else
   printf("%s \n",passwd->pw_passwd);

 }


 


 return 0;

}
