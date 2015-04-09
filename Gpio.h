#ifndef GPIO_H_
#define GPIO_H_

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





#include "Gpiodef.h"

class  Gpio
{

private:

	char  whole[256];
	bool isCreated(char*);
	const int number;

	//direction direct;
public:

	enum direction {in,out};
			
	Gpio(int number,Gpio::direction direct,std::ofstream* exportHandler=0,std::ofstream* unexportHandler=0);
	
	bool open();
	bool close();	

	//SETTER
	bool setValue(int value);
	bool setDirection(direction direct);	
	
	//GETTER
	bool getValue();	
	direction getDirection();
private:
		
	direction direct;
};

#endif
