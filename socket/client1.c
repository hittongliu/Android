#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stddef.h>
#include <sys/un.h>
#include <string.h>
#define SOCKFILE "foo.socket"
#define MAX 1024

int main(int argc, char *argv[])
{
    static struct sockaddr_un serveraddr;
    char buf[MAX] = "hello world form thr client";
    int clientfd;

    clientfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (clientfd < 0) {
        printf("socket() wrong!\n");
        return 0;
    }
    serveraddr.sun_family = AF_UNIX;
    snprintf(serveraddr.sun_path, sizeof(serveraddr.sun_path), SOCKFILE);
    socklen_t len_t = sizeof(struct sockaddr_un);

    connect(clientfd, (struct sockaddr *)&serveraddr, len_t);
    send(clientfd, buf, strlen(buf), 0);
}