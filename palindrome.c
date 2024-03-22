#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char a[20];
    int flag=0;
    scanf("%s",a);
    int l=strlen(a);
    printf("%d\n",l/2);
    for(int i=0;i<l/2;i++){
        printf("%c\t %c\n",a[i],a[l-1-i]);
        if(a[i]!=a[l-1-i]){
            flag=1;
        }
    }
    if(flag==1){
        printf("not a palindrome");
    }
    else{
        printf("palindrome");
    }
}