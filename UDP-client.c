#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define port 8080
int main(){
    int socket_df;
    ssize_t val;
    struct sockaddr_in serveraddr,clientaddr;
    char *msg ="this program is using UDP(client)";
    char buffer [1024]={0};
    
    if((socket_df=socket(AF_INET,SOCK_DGRAM,0))<0){
        perror("socket formation error");
        exit(0);
    }
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(port);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if((connect(socket_df,(struct sockaddr*)&serveraddr,sizeof(serveraddr)))<0){
        perror("Error in connection");
        exit(0);
    }

    sendto(socket_df,msg,strlen(msg),0,(struct sockaddr*)NULL,sizeof(serveraddr));
    recvfrom(socket_df,buffer,1024,0,(struct sockaddr*)NULL,NULL);
    printf("%s\n",buffer);
    close(socket_df);
}