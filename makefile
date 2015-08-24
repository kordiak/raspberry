a.out : libgpio.a t.cpp Gpio.h
	g++ t.cpp -L.  -lgpio
libgpio.a : Gpio.o
	ar rsc libgpio.a Gpio.o
Gpio.o : Gpio.cpp Gpio.h
	
	g++ -c Gpio.cpp  
clean : 
	rm *.o *.a
