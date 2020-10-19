#include<stdio.h>
#include<string.h>

int main()
{
    FILE* imageFile = fopen("image.jpeg","ab");
    
    char* myMessage = "you have been hacked";

    if(imageFile == NULL)
    {
        printf("file not found \n");
        return -1;
    }
        
    fwrite(myMessage,sizeof(*myMessage),strlen(myMessage)-1,imageFile);
    fclose(imageFile);

    return 0;

}