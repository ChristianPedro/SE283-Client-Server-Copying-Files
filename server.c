#include "csapp.h"
#include "csapp.c"
void echo(int connfd)
{
    size_t n;
    char buf[MAXLINE];
	 char prebuf[MAXLINE];
    rio_t rio;
	 rio_t tio;
	 Rio_readinitb(&rio, connfd);
	 Rio_readlineb(&rio, prebuf, MAXLINE);
	 int myfile;
	 char * temp = strtok(prebuf, " ");
	 char * thefile = strtok(NULL, " ");
	 thefile++;
	 myfile = open(thefile, O_RDONLY, 0);
	 Rio_readinitb(&tio, myfile);
 	while((n = Rio_readlineb(&tio, buf, MAXLINE)) != 0){
        printf("server received %ld bytes\n", n);
        Rio_writen(connfd, buf, n);
		  //printf("value of n: %d \n", (int)n);
		 
	 }
close(myfile);
close(connfd);
//printf("echo done");
}



int main(int argc, char **argv)
{
int listenfd, connfd, port, clientlen;
struct sockaddr_in clientaddr;
struct hostent *hp;
char *haddrp;
if (argc != 2) {
fprintf(stderr, "usage: %s <port>\n", argv[0]);
exit(0);
}
port = atoi(argv[1]);

listenfd = Open_listenfd(port);
while (1) {
printf("waiting for connection..\n");
clientlen = sizeof(clientaddr);
connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
/* Determine the domain name and IP address of the client */
hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
sizeof(clientaddr.sin_addr.s_addr), AF_INET);
haddrp = inet_ntoa(clientaddr.sin_addr);
printf("server connected to %s (%s)\n", hp->h_name, haddrp);
echo(connfd);
//printf("this is after the close");
}
exit(0);
}
