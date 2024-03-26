#include<stdio.h>
int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a[]={1,3,7,9,0,2,4,5,8,6};
    int l=sizeof(a)/4;
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
    for(int i=0;i<l;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}