#include<stdio.h>
#include<string.h>
int square(int a,int b){
    printf("Square of two numbers: %d\n", a*a);
    printf("Square of  second number: %d\n",b*b);
}
int main(int argc,char*argv[]){
    int a,b;
    char s[] ="1";
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("%s\n",s);
    if(argv[1]==s){
    int c = a*b;
    printf("The product of two numbers %d \n", c);
    }
    else{
        square(a,b);
    }
    return 0;
}