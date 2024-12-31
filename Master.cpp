//Set the clock
#ifndef F_CPU
#define F_CPU 8000000UL	//Clock expressed in MHz
#endif

//Set the BAUD rate
#ifndef BAUD
#define BAUD 9600
#endif

#include <avr/io.h>
#include <util/delay.h>

//-----------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------//
//SPI in Master mode
void SPI_MasterInit()
{
	
	//PB2 = SS, PB3 = MOSI, PB5 = SCK
	DDRB |= (1 << DDB3) | (1 << DDB2) | (1 << DDB5);	//1 = Output
		
	// Enable SPI, Master, set clock rate fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);

}

//Start the transmission of the data
void SPI_MasterTransmit(char cData)
{
	
	//Save the info to be transmitted into SPDR
	SPDR = cData;
	
	//Wait for transmission complete. When the transmission is complete, SPIF is set to "1" 
	while(!(SPSR & (1 << SPIF)))
	{
			
		//Do nothing
		
	}
	
	
}

//-----------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------//


int main(void)
{

SPI_MasterInit();

int flag_data = 2;

//Characters to be transmitted
char string_transm[] = {'H','e','l','l','o',' ','W','o','r','l','d'};

//Size of the array of characters
int elements = sizeof(string_transm) / sizeof(string_transm[0]);

while(1)
{
	
	PORTB &= ~(1 << PORTB2);	//Enable the transmission of the data in Master mode
	_delay_ms(5000);
	
	if (flag_data % 2 == 0)
	{
		
		for (int kk = 0; kk < elements; kk++)
		{
 
			SPI_MasterTransmit(string_transm[kk]);
		
		}
		
 flag_data++;
 
	}
	
	else
	{
	
	SPI_MasterTransmit(0x21);	//ASCII code for "!"
		
		flag_data++;
		
	}
	
	
 PORTB |= (1 << PORTB2);	//Disable the transmission of the data in Master mode
 
 _delay_ms(5000);
 
}


}
