
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <vector>


#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



#include "Gpio.h"



#include <thread>
#include <chrono>


bool Gpio::isCreated(char * tab) 
{

	sprintf(whole,"/sys/class/gpio/gpio%s",tab);
	struct stat sb;
	return (stat(whole,&sb)==0 && S_ISDIR(sb.st_mode));	

};

bool Gpio::setDirection(direction direct)
{
	this->direct=direct;
	char buffer[256];

	sprintf(buffer,"%s/direction",whole);
	printf("%s",buffer);
	std::ofstream directionFile;
	

	directionFile.open(buffer);

    if (directionFile.fail())
		{	
			return false;			
		}

	printf("SETTING DIRECTION\n");

	switch(direct)
	{
		case in:	directionFile << "in"; 
				break;
		case out: 	

	///			printf("\nOUT\n");
				directionFile << "out"; 
				break;

	}	


	
	return true;
}

Gpio::Gpio(int number,Gpio::direction direct,std::ofstream * exportHandler,std::ofstream * unexportHandler): number(number),direct(direct) 
{
			
};
bool Gpio::open()
{

	printf("OPENING\n");

	char tab[256];
	sprintf(tab,"%d",number);

	if(this->isCreated(tab))
		printf("already exist\n");
//		throw new std::string("auc");

	//TODO : EXCEPTION
	
	std::ofstream exportgpio(EXPORT_PATH.c_str());

	
	
	
	if(exportgpio.fail())
	{
	 printf("ERROR");
	 return false;
	}	
	exportgpio << tab;
	
	exportgpio.close();

	std::this_thread::sleep_for (std::chrono::seconds(5));
	
	this->setDirection(this->direct);

	return true;
};


bool Gpio::close()
{

	
	char tab[10];

	sprintf(tab,"%d",number);

	printf("CLOSING\n");

	std::ofstream unexportgpio(UNEXPORT_PATH.c_str());

	if(unexportgpio.fail())
	{
		printf("ERROR");
		return false;
	}
	
		

	unexportgpio << tab;
	unexportgpio.close();
	return true;	
}


bool Gpio::setValue(int value)
{

	char buffor[512];

	sprintf(buffor,"%s/value",whole);

//	printf("%s",buffor);

	std::ofstream valueFile(buffor);

	if(valueFile.fail())
		printf("ERROR");
	
	valueFile << value;

	valueFile.close(); 
	return true;	
}
