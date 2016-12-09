#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <string.h>

#define SOCKFILE "foo.socket"
#define MAX 1024

int main(int argc, char *argv[])
{
    int serverfd;
    int clientfd;
    char buf[1024];
    struct sockaddr_un servaddr;
    struct sockaddr_un clientaddr;
    servaddr.sun_family = AF_UNIX;
    snprintf(servaddr.sun_path, sizeof(servaddr.sun_path), SOCKFILE);

    serverfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (serverfd < 0) {
        printf("error\n");
        return 0;
    }

    if (bind(serverfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_un)) == -1) {
        printf("bind wrong!\n");
        // close(servaddr);
        return 0;
    }

    listen(serverfd, 1);

    int len_t = sizeof(clientaddr);
    if((clientfd = accept(serverfd, (struct sockaddr *)&clientaddr, (socklen_t *)&len_t)) == -1 ) {
        printf("accept wrong!\n");
        // close(serverfd);
        return 0;
    }
    recv(clientfd, buf, sizeof(buf), 0);
    printf("%s\n", buf);
    return 0;
}