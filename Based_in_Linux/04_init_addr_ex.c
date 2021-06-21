// Example Init Internet Address

// struct sockaddr_in addr;		//
// char *serv_ip = "xxx.xxx.xxx.xx";	// IP주소 문자열 선언
// char *serv_port = "xxxx";		// PORT 번호 문자열 선언
// memse(&addr, 0, sizeof(addr))	// addr의 모든 멤버 0으로 초기화
// addr.sin_family = AF_INET;		// 주소체계 지정, IPv4
// addr.sin_addr.s_addr = inet_addr(serv_ip)	// 32비트 형태로 IP주소 초기화
// addr.sin_port = htons(atoi(serv_port));	// PORT 번호 초기화


// addr.sin_addr.s_addr = inet_addr(INADDR_ANY); 로 대체 가능
