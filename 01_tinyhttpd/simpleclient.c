#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
 int sockfd;
 int len;
 struct sockaddr_in address;
 int result;
 char ch = 'A';
 char str1[128] = "Hello World!", str2[128] = {0};
 

 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 address.sin_family = AF_INET;
 address.sin_addr.s_addr = inet_addr("127.0.0.1");//服务端和客户端运行在同一PC上时的IP
 address.sin_port = htons(10086);//该端口要与服务端的端口一致
 len = sizeof(address);
 result = connect(sockfd, (struct sockaddr *)&address, len);

 if (result == -1)
 {
  perror("oops: client1");
  exit(1);
 }
 #if 0
 write(sockfd, &ch, 1);
 read(sockfd, &ch, 1);
 printf("char from server = %c\n", ch);
 #else //add by zjc
 write(sockfd, &str1, strlen(str1));
 //memset(&str1, 0, strlen(str1));
 read(sockfd, &str1, strlen(str1));
 printf("string from server = %s\n", str1);

 #endif
 close(sockfd);
 exit(0);
}
