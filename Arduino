#include<SPI.h>

volatile boolean received;
volatile byte receivedData;

int track_chars = 0;

ISR (SPI_STC_vect)        //Inerrrput routine function 
{

receivedData = SPDR;   // Get the received data from SPDR register
  received = true;       // Sets received as True 

}

void setup()
{
  
Serial.begin(9600);

  pinMode(MISO,OUTPUT);   //Sets MISO as OUTPUT
  SPCR |= _BV(SPE);       //Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();  //Activate SPI Interuupt 

}


void loop()
{ 

  if(received) 
{                        
    
    received = false;
    //Serial.print(receivedData, HEX);  
    Serial.write(receivedData);
    track_chars++;
    
    if (track_chars > 11)
    {

    Serial.print("\n");
    track_chars = 0;
    
    }
  }
}
