#include<stdio.h>
int main(){
    int a[]={1,3,7,9,0,2,4,5,8,6};
    int l=sizeof(a)/4;
    for(int i=0;i<l;i++){
        int j=i-1;
        int k=a[i];
        while(j>=0 && a[j]>k){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
    for(int i=0;i<l;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}