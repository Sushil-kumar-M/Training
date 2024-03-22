#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#define port 8080
int main(){
    int socket_fd;
    ssize_t val;
    struct sockaddr_in serveraddr,clientaddr;
    char *msg ="this prpgram is using UDP(server)";
    char buffer [1024]={0};
    
    if((socket_fd=socket(AF_INET,SOCK_DGRAM,0))<0){
        perror("socket formation error");
        exit(0);
    }
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(socket_fd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        perror("binding error");
        exit(0);
    }
    int len=sizeof(clientaddr);
    recvfrom(socket_fd,buffer,1024,0,(struct sockaddr*)&clientaddr,&len);
    printf("%s\n",buffer);
    sendto(socket_fd,msg,strlen(msg),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
    close(socket_fd);

}
