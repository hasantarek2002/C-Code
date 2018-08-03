#include <stdio.h>
#include <string.h>

int main ()
{

    /*
    char c1 = 0xFF; char c2 = 0xFE;
if((int)c1 == 0xFF && (int)c2 == 0xFE)
{
    //do something
}
*/
   char src[50], dest[50];
    unsigned char a=0x08;
    unsigned char b=0x06;

   //printf("%s", src);

    if((int)a==0x08 && (int)b==0x06)
    {
        printf("A is matched");
    }
   else
   {
       printf("A is not matched");
   }

   return(0);
}
