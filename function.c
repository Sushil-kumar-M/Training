#include<stdio.h>
void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
    printf("%d %d",a,b);
}
int main(){
    int a=4;
    int b=5;
    void(*fun_ptr)(int,int)=swap;
    (fun_ptr)(a,b);
}