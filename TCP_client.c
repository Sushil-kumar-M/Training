#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#define port 8080
int main(){
    int socket_fd;
    ssize_t val;
    struct sockaddr_in sockaddr;
    char buffer[1024]={0};
    char a[20];
    scanf("%s",a);
    char *string1=a;

    if((socket_fd=socket(AF_INET,SOCK_STREAM,0))<0){
        perror("socket forming error");
        exit(0);
    }

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr =inet_addr("127.0.0.1");
    sockaddr.sin_port = htons(port);

    if(connect(socket_fd,(struct sockaddr*)&sockaddr,sizeof(sockaddr))<0){
        perror("connection failed");
        exit(0);
    }

    write(socket_fd,string1,strlen(string1));
    val=read(socket_fd,buffer,1024-1);
    printf("%s\n",buffer);
    close(socket_fd);

}