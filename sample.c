#include<stdio.h>
int square(int a,int b){
    printf("Square of two numbers: %d\n", a*a);
    printf("Square of  second number: %d\n",b*b);
}
int main(){
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    int c = a*b;
    square(a,b);
    printf("The product of two numbers %d \n", c);
}