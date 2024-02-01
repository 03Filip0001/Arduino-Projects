#include<SPI.h>
#define LED 7
volatile boolean received;
volatile byte Slavereceived;

void setup()

{
  Serial.begin(115200);

  pinMode(LED, OUTPUT);              
  pinMode(MISO, OUTPUT);        //Postavlja MISO kao OUTPUT jer mora da salje podatke masteru
  SPCR |= _BV(SPE);             //Ukljucuje SPI u slave modu
  received = false;

  SPI.attachInterrupt();        //Interapt je ukljucen za SPI komunikaciju
}

ISR (SPI_STC_vect)                        
{
  Slavereceived = SPDR;         //Vrednost dobijena iz mastera smestena u Slavereceived
  received = true;              
}

void loop()
{
  if (received)                          
  {
    if (Slavereceived == 1)
    {
      digitalWrite(LED, HIGH);        
      Serial.println("Slave LED ON");
    } else
    {
      digitalWrite(LED, LOW);         
      Serial.println("Slave LED OFF");
    }
    
    SPDR = 0;                    //Salje vrednost 0 masteru preko SPDR (1 bajt)
  }
}
