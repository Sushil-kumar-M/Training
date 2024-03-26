#include<stdio.h>
int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int part(int a[],int low,int high){
    int pivot=a[high-1];
    int i=0;
    for(int j=0;j<high-1;j++){
        if(a[j]<pivot){
            swap(&a[i],&a[j]);
            i++;
        }
    }
    a[i]=a[high-1];
    return i;
}
int quickcal(int a[],int low,int high){
    if(low<high){
        int p=part(a,low,high);
        quickcal(a,low,p-1);
        quickcal(a,p+1,high);
    }
}
int main(){
    int a[]={1,3,7,9,0,2,4,5,8,6};
    int l=sizeof(a)/4;
    quicksort(a,0,l);
    for(int i=0;i<l;i++){
        printf("%d",a[i]);
    }
}