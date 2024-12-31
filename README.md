# SPI
SPI with ATMEGA328p

These two simple files are used to have two arduino boards communicate with one another. While I am aware that what I am posting is something very basic, I hope it can be of some help to people new to microcontrollers. You will need two arduino boards to execute this code and the ATMEL ICE to burn the code provided in the file named "Master", as that code was written in Microchip Studio. Alternatively, you can obviously have one arduino board and buy an ATMEGA328p microcontroller and use it on your own board. 

1) The file namedd "Arduino_Slave.cpp" is used to set the first arduino board in a Slave mode. The code that be found on the arduino website stackexchange. The output can be changed to plot the bytes sent in hexadecimal, binary, etc. See the function Serial.print provided by arduino;

2) The file named "Master.cpp" is used to set the second arduino board in a Master mode. This code was written in Microchip Studio and was burnt into ATMEGA328p by using ATMEL ICE.

The output is: "Hello World!".

I hope that this code can be useful to soemone. 

If you have any questions and/or want to report bugs, please e-mail me (Ale) at: pressalex@hotmail.com
