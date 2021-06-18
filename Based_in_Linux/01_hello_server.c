#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "Hello World!";

	if(argc != 2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock = socket(PF_INET, SOCK_STREAM, 0); // socket 함수호출을 통해서 소켓 생성
	if(serv_sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);	// h(호스트), n(네트워크) 즉, h to n l: long형 데이터를 호스트 바이트 순서에서 네트워크 바이트 순서로 바꿔라!
	serv_addr.sin_port = htons(atoi(argv[1]));	// h(호스트), n(네트워크) 즉, h to n s: short형 데이터를 호스트 바이트 순서에서 네트워크 바이트 순서로 바꿔라!

	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) // bind 함수호출을 통해 IP주소와 PORT번호 할당
		error_handling("bind() error");

	if(listen(serv_sock, 5) == -1) // listen 함수를 호출, 이로써 소켓은 연결요청을 받아들일 수 있는 상태가 된다.
		error_handling("listen() error");

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_addr, &clnt_addr_size); // 연결요청의 수락을 위한 accept 함수
	if(clnt_sock == -1)
		error_handling("accept() error");

	write(clnt_sock, message, sizeof(message)); // 데이터 전송 기능 함수
	close(clnt_sock);
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
