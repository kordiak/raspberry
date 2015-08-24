#ifdef __MAC_10_0
    #include <unistd.h>
#endif


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <vector>

#include <unistd.h>
#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//#include "Gpiodef.h"
#include "Gpio.h"
//#include <netinet/in.h>


class Messenger
{

};

class Connection
{
	private:
	std::vector<int> sockets;
	std::vector<int> activeSockets;	
	
		
	
	public:
	enum state { disconnected,connected};
	

	void openConnection();
	void closeConnection();

	

};

void Connection::openConnection()
{
	//Listen to connection
	//Handle connection -> create new socket
	//
}








void error(char *msg)
{
	std::perror(msg);
	exit(1);
}



sockaddr_in serv_addr,cli_addr;

int main()
{

	Gpio gpio27(27,Gpio::out);
	Gpio gpio22(22,Gpio::out);
	gpio27.open();
	gpio22.open();


	gpio22.setValue(1);
	int i=10;
	while(i>0)
	{
	i--;
	gpio27.setValue(1);
	usleep(70000);
	gpio27.setValue(0);
	usleep(70000);	
	}





	gpio27.close();
	gpio22.close();
};

/*
int main2(int argc, char *argv[])
{

	int sockfd,newsockfd,portno,n;
	unsigned int clilen;
	char buffer[256];

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		{
			error(static_cast<char*>("Error opening socket"));
		}
	memset(&serv_addr,'\0',sizeof(serv_addr));

	portno=atoi(argv[1]);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(portno);
	
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	if(bind(sockfd,(sockaddr*) &serv_addr,sizeof(serv_addr))<0)
		error("Error on binding");	
	
	listen(sockfd,5);
	clilen=sizeof(cli_addr);
	
	newsockfd=accept(sockfd,(sockaddr*)&cli_addr,static_cast<socklen_t*>(&clilen));
	if(newsockfd<0)
		printf("BLAD");
	//error("Error on accept");
	
	

	//char buffer[256]='\0';
	n=recv(newsockfd,buffer,255,0);
	if(n<0) printf("ERROR reading from socket");
	else
	printf("Here is the message: %s",buffer);
	
	send(newsockfd,"I got your",6,0);
	

	shutdown(newsockfd,SHUT_RDWR);
		





//error(argv[0]);
return 0;
}
 */
