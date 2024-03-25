#include<stdio.h>
int main(){
    int arr[]={12,23,34,12,12,23,12,45};
    int k=arr[0];
    int x=0,y=0;
    for(int i=1;i<8;i++){
        k=k^arr[i];
    }
    int set= k & ~(k-1);
    for(int i=0;i<8;i++){
        if(arr[i]&set){
            x=x^arr[i];
        } 
        else{
            y=y^arr[i];
        }
    }
    printf("%d\t%d\n",x,y);
}