#include<stdio.h>
#include<string.h>
#define size 5
#define size1 3
int arr[5] = { 0 };
int key;

int lp(int key,int val){
    while(arr[key]!=0){
        key=(val%size+1);
    }
    return key;
}

int qp(int key,int val){
    int i=0;
    while(arr[key]!=0){
        key=(val%size+i*i);
        i++;
    }
    return key;
}

int dh(int key,int val){
    int i=0;
    while(arr[key]!=0){
        key=(val%size+i*(val%size1));
        i++;
    }
    return key;
}

int keycal(int val){
    int opt;
    key=val%size;
    int flag=0;
    flag=insert(key,val);
    if(flag==1){
        printf("Enter the collision algo  selected : ");
        printf("1.Linear prob");
        printf("Quadratic prob");
        printf("Double hashing");
        scanf("%d", &opt);
        if(opt==1){
            key=lp(key,val);
        }
        else if(opt==2){
            key=qp(key,val);
        }
        else{
            key=dh(key,val);
        }
    }
    insert(key,val);
}

int insert(int k, int val){
    keycal(val);
    if(arr[k]==0){
        arr[k]=val;
        return 0;
    }else{
        return 1;
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