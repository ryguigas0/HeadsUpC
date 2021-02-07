#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>

void errormsg(char *msg)
{
    fprintf(stderr, "%s: %s", msg, strerror(errno));
    exit(1);
}

int open_socket(char *addr, char *port)
{
    struct addrinfo *res = NULL;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(addr, port, &hints, &res);

    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (s == -1)
        errormsg("Não pode criar socket");

    int c = connect(s, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);
    if (c == -1)
        errormsg("Can't connect to ip");
    return s;
}

int say(int socket, char *msg)
{
    int res = send(socket, msg, strlen(msg), 0);
    if (res == -1)
        fprintf(stderr, "Could'nt send bytes: %s", strerror(errno));
    return res;
}

int main(int argc, char const *argv[])
{
    int d_sock;
    d_sock = open_socket("en.wikipedia.org", "80");
    
    char buf[255];
    sprintf(buf, "GET /wiki/%s http/1.1\r\n", argv[1]);
    say(d_sock, buf);

    say(d_sock, "HOST: en.wikipedia.org\r\n\r\n");

    char rec[256];
    int bytesRecv = recv(d_sock, rec, 255, 0);
    while (bytesRecv)
    {
        if(bytesRecv == -1)
            errormsg("Can't read from server");
        rec[bytesRecv] = '\0';
        printf("%s", rec);
        bytesRecv = recv(d_sock, rec, 255, 0);
    }
    close(d_sock);
    return 0;
}
