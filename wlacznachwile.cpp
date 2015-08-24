#include "Gpio.h"

int main()
{

	Gpio gpio27(27,Gpio::out);
        Gpio gpio22(22,Gpio::out);
       
	gpio27.open();
        gpio22.open();


        gpio27.setValue(1);
	gpio22.setValue(1);	
//        gpio27.setValue(1);
        usleep(2000000);
        gpio27.setValue(0);
        
//        gpio22.setValue(1);
//	usleep(2000000);
	gpio22.setValue(0);





        gpio27.close();
        gpio22.close();
return 0;
}
