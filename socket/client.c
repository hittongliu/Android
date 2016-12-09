#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_SOCKET 1024
#define PORT_SOCKET 8888

int main(int argc, char *argv[]) {

    int clientfd;
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    //客户端地址
    char *ipbuf = "127.0.0.1";
    char sendbuf[MAX_SOCKET] = "赵鸿宁向哥哥问好~";
    printf("%s\n", sendbuf);
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT_SOCKET);
    // 将点分的ip地址转换为网络字节地址
    inet_aton(ipbuf, &servaddr.sin_addr);
    connect(clientfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    send(clientfd, sendbuf, strlen(sendbuf), 0);
    recv(clientfd, sendbuf, sizeof(sendbuf), 0);
    printf("%s\n", sendbuf);
}