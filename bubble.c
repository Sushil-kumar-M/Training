#include<stdio.h>
int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a[]={1,3,7,9,0,2,4,5,8,6};
    int l=sizeof(a)/4;
    for(int i=0;i<l;i++){
        for(int j=0;j<l-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
    for(int i=0;i<l;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}