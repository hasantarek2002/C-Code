#include<stdio.h>
#include<string.h>

int main(){
    char name[20];

    scanf("%s",&name);

    if(strcmp(name,"Sumon")==0){
        printf("Boy");
    }
    else{
        printf("Girl");
    }

    return 0;
}
