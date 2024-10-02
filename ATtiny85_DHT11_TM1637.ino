#include "DHTStable.h"
#include <TM1637Display.h>

#define TEMPTYPE 0        // Use Fahrenheit (0 for celsius)
#define DHTTYPE DHT11     // DHT 22  (AM2302)
#define DHT11_PIN       2
#define CLK 0
#define DIO 1

#define DHTTYPE DHT11

TM1637Display display = TM1637Display(CLK, DIO);
DHTStable DHT;

const uint8_t SEG_GRAUS[] = {
  SEG_A | SEG_B | SEG_G | SEG_F, // º
  };

const uint8_t SEG_LC[] = {
  SEG_A | SEG_F | SEG_E | SEG_D // C
  };

const uint8_t SEG_HUM1[] = {
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G, // Representa a letra "H"
  };

const uint8_t SEG_HUM2[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_F // Representa a letra "u"
  };


void setup() 
{
  display.setBrightness(3);
  delay(2000);
} 
  
void loop() 
{
  int chk = DHT.read11(DHT11_PIN);
  int humid = DHT.getHumidity();               // Read humidity
  int temp = DHT.getTemperature();   // read temperature
  display.clear();
  display.showNumberDec(humid, false, 2, 0); // Expect: ___0
  display.setSegments(SEG_HUM1, 2, 3);
//  display.setSegments(SEG_HUM2, 2, 3);
  delay(3000);
  display.clear();
  display.showNumberDec(temp, false, 2, 0); // Expect: ___0
  display.setSegments(SEG_GRAUS, 1, 2);
  display.setSegments(SEG_LC, 2, 3);  
  delay(10000);
}