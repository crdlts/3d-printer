#include <SPI.h>
#include <SD.h>
#include "define.h"
#include "3os.h"
#include "cordinate.h"
#include "priem_chisla.h "
#include "ti_mer.h "
#include "tra.h"
#include "setup.h"
#include "loop.h"

void setup()
{
   
  setup1();
  if(!SD.begin(5)){
    Serial.println("Card Mount Failed");
   // return;
  }
  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
   // return;
  }
  file = SD.open(path);
}

void loop()
{
  loop1();
}
