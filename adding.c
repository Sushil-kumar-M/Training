#include<stdio.h>
int main(){
    int a=15;
    int b=15;
    while(b!=0){
        int carry=a&b;
        printf("%d\t",carry);
        a=a^b;
        printf("%d\t",a);
        b=carry<<1;
        printf("%d\t",b);
        printf("\n");
    }
    printf("\n%d\n",a);
}