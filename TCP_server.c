#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#define port 8080
int main(){
    int socket_fd,new_socket_fd;
    ssize_t val;
    struct sockaddr_in sockaddr,clientaddr;
    char buffer[1024]={0};
    char buffer1[20]={0};
    char *string2 = buffer1;
    int caddrlen=sizeof(clientaddr);

    if((socket_fd=socket(AF_INET,SOCK_STREAM,0))<0){
        perror("socket forming error");
        exit(0);
    }

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(port);

    if((bind(socket_fd,(struct sockaddr*)&sockaddr,sizeof(sockaddr)))<0){
        perror("binding problem");
        exit(0);
    }

    if(listen(socket_fd,3)<0){
        perror("listening error");
        exit(0);
    }
    
    if((new_socket_fd=accept(socket_fd,(struct sockaddr*)&clientaddr,&caddrlen))<0){
        perror("Error in acceptance");
        exit(0);
    }

     val=read(new_socket_fd,buffer,1024-1);
     printf("%s\n",buffer);
     int l=strlen(buffer);
     int flag=0;
     for(int i=0;i<l/2;i++){
        if(buffer[i]!=buffer[l-1-i]){
            flag=1;
        }
    }
     if(flag==1){
        strcpy(buffer1,"NOT_palindrome");
     }
     else{
        strcpy(buffer1,"Palindrome");
     }
     write(new_socket_fd,string2,strlen(string2));
    close(new_socket_fd);
    close(socket_fd);
    exit(0);
}