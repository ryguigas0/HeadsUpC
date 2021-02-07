#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <signal.h>

int listener_d;

void errormsg(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int catchSignal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

void handleTerminate(int sig)
{
    if (listener_d)
        close(listener_d);
    fprintf(stdout, "\nAdeus!\n");
    exit(0);
}

int openListenerSocket()
{
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1)
        errormsg("Can't create socket");
    return listener_d;
}

int bindSocketListener(int socket, int port)
{
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == 1)
        errormsg("Can't set the reuse option for the socket");

    int isBinded = bind(socket, (struct sockaddr *)&name, sizeof(name));
    if (isBinded == -1)
        errormsg("Can't bind socket");
    return isBinded;
}

int socketListenerAcceptConection(int socket)
{
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    return accept(socket, (struct sockaddr *)&client_addr, &address_size);
}

int socketListen(int socket, int limit)
{
    int result = listen(socket, limit);
    if (result == -1)
        errormsg("Socket can't listen");
}

int closeSocketConnection(int socketConn)
{
    int result = close(socketConn);
    if (result == -1)
        errormsg("Can't close connection in socket");
    return result;
}

int say(int conn, char *msg)
{
    int result = send(conn, msg, strlen(msg), 0);
    if (result == -1)
        fprintf(stderr, "Can't send bytes through socket: %s\n", strerror(errno));
    return result;
}

int read_in(int socket, char *buf, int len)
{
    char *s = buf;
    int slen = len;
    int c = recv(socket, buf, slen, 0);
    while (c > 0 && (s[c - 1] != '\n'))
    {
        s += c;
        slen -= c;
        c = recv(socket, buf, slen, 0);
    }
    if (c < 0)
        return c;
    else if (c == 0)
        buf[0] = '\0';
    else
        s[c - 1] = "\0";

    return len - slen;
}

int main(int argc, char const *argv[])
{
    if (catchSignal(SIGINT, handleTerminate) == -1)
    {
        fprintf(stderr, "Can't handle the handler\n");
    }

    listener_d = openListenerSocket();
    bindSocketListener(listener_d, 30000);
    socketListen(listener_d, 10);

    puts("Waiting for conection");

    while (1)
    {
        int conn = socketListenerAcceptConection(listener_d);
        say(conn, "Internet Knock Knock Protocol Server\nVersion 1.0\nKnock, knock!>\r\n");
        if (fork() == 0)
        {
            close(listener_d);

            char recieved[200];
            read_in(conn, recieved, 200);

            if (strcmp(recieved, "Whos there?"))
            {
                closeSocketConnection(conn);
                continue;
            }

            say(conn, "Oscar.>\r\n");
            read_in(conn, recieved, 200);
            if (!strcmp(recieved, "Oscar who?"))
            {
                closeSocketConnection(conn);
                continue;
            }
            say(conn, "Oscar a silly question, you get a silly answer!\r\n");
            closeSocketConnection(conn);
            exit(0);
        }
        close(conn);
    }
    return 0;
}
