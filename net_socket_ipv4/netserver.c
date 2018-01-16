#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 256

int main(int argc, char ** argv)
{
	char buf[BUF_SIZE];

	if( argc < 3 ) 
	{
		fprintf(stderr,"usage: %s <port_number>\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	int sock = socket(AF_INET /* Домен сокета - сетевой */, SOCK_STREAM /* Тип сокета - потоковый */, AF_INET);
	if( socket < 0 )
	{
		printf("socket() failed: %d\n", errno);
		return EXIT_FAILURE;
	}
	struct sockaddr_in server_addr;
	memset( (char *) &server_addr, 0, sizeof(server_addr) );
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]); //INADDR_ANY;
	
	int port = atoi(argv[2]);
	server_addr.sin_port = htons(port);

	if( bind( sock, (struct sockaddr *) &server_addr, sizeof(server_addr) ) < 0 )
	{
		printf("bind() failed: %d\n", errno);
		return EXIT_FAILURE;
	}
	
	/* Количество возможных подключений к серверу */
	listen(sock, 5);

	struct sockaddr_in cli_addr;
	int addr_len = sizeof(cli_addr);
	printf( "%i !!!\n", inet_addr(argv[1]) ); ///////
	int newsock = accept( sock, (struct sockaddr *) &cli_addr, &addr_len );
	if( newsock < 0 ) 
	{
		printf("accept() failed: %d\n", errno);
		return EXIT_FAILURE;
	}
	printf( "%i !!!!\n", inet_addr(argv[1]) ); ///////
	memset( buf, 0, BUF_SIZE );

	read( newsock, buf, (BUF_SIZE - 1) );
	buf[BUF_SIZE] = 0;
	printf("Input Message: %s\n", buf);
	write(newsock, "OK\n", 3);
	close(newsock);
	close(sock);
}
