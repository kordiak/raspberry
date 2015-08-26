{
	"targets": 
	[
		{
			"target_name":"gpio",
			"sources": ["gpio.cc"]
		},
		{
			"target_name":"addon",
			"sources": ["addon.cpp", "myobject.cpp","Gpio.cpp","Gpio.h","Gpiodef.h"],
			"cflags": ["-std=c++0x"]
		}
	]

}
