#include<stdio.h>
#include<string.h>

int main()
{
    FILE* imageFile = fopen("image.jpeg","ab");
    char* myMessage = "you have been hacked";

    if(imageFile == NULL)
    {
       return -1;
    }
        
    fwrite(myMessage,sizeof(*myMessage),strlen(myMessage),imageFile);
    fclose(imageFile);

    return 0;

}
