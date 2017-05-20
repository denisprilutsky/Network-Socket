#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SOCK_NAME "socket.soc"
#define BUF_SIZE 256

int main(int argc, char ** argv)
{
	struct sockaddr srvr_name, rcvr_name;
	char buf[BUF_SIZE];
	int sock;
	int namelen, bytes;
	/* Получаем дескриптор сокета */
	sock = socket(AF_UNIX /* Домен сокета - файловое пространство имен */, SOCK_DGRAM /* Тип сокета - дейтаграммный */, 0 /* Протокол передачи данных */);
	if( sock < 0 ) 
	{
		perror("socket failed");
		return EXIT_FAILURE;
	}
	
	srvr_name.sa_family = AF_UNIX;
	strcpy(srvr_name.sa_data, SOCK_NAME);

	/* Связываем сокет с заданным адресом */
	if( bind( sock, &srvr_name, strlen(srvr_name.sa_data) + sizeof(srvr_name.sa_family) ) < 0 ) 
	{
		perror("bind failed");
		return EXIT_FAILURE;
	}
	printf("!!!!!\n");
	/* Адрес клиента - для файлового сокета не несет информации */
	bytes = recvfrom(sock, buf, sizeof(buf), 0, &rcvr_name, &namelen);
	if (bytes < 0) 
	{
		perror("recvfrom failed");
		return EXIT_FAILURE;
	}
	printf("!!!!!\n");
	buf[bytes] = 0;
	rcvr_name.sa_data[namelen] = 0;
	printf("Client sent: %s\n", buf);
	close(sock);
	unlink(SOCK_NAME);
}
