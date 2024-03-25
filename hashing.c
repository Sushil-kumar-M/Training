#include<stdio.h>
#include<string.h>
#define size 5
int arr[5] = { 0 };
int insert(int val){
    int k=val%size;
    if(arr[k]==0){
        arr[k]=val;
    }else{
        printf("The space is not empty");
    }
}
int delete(int val){
    int k=val%size;
    if(arr[k]==val){
        arr[k]=0;
    }else{
        printf("already empty");
    }
}
int serach(int val){
    int k=val%size;
    if(arr[k]==val){
        printf("the element found at %d",k+1);
    }else{
        printf("the element not found");
    }
}
int display(){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}
int main(){
    int n;
    for(int j=0;j<5;j++){
    printf("Enter the element to be inserted : ");
    scanf("%d", &n);
    insert(n);
    }
    display();
    printf("\nEnter the number to be deleted : ");
    scanf("%d",&n);
    delete(n);
    printf("\n");
    display();
    printf("\n");
}