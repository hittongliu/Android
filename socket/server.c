#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define SERVER_PORT 8888
#define MAX_SOCKET 1024

int main(int argc, char *argv[]) {

    int serverfd;
    int clientfd;
    socklen_t socktlen;
    int error;
    struct sockaddr_in clientaddr;
    char buf[MAX_SOCKET];
    // 定义服务器端点地址结构
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT);

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(serverfd, (struct sockaddr *)&servaddr, sizeof
        (struct sockaddr_in));
    // 服务器所能够等待的客户端连接请求的个数。这时候处于等待状态，还不能进入到accept
    listen(serverfd, 20);
    while((clientfd = accept(serverfd, (struct sockaddr *)&clientaddr,
            &socktlen)) != -1) {
        if (recv(clientfd, buf, sizeof(buf), 0) == -1) {
            printf("error\n");
            return 0;
         }
        printf("server receives the message\n");
        printf("%s\n",buf);
        sprintf(buf, "哥哥向赵鸿宁妹妹问好~");
        send(clientfd, buf, strlen(buf), 0);
    }
}