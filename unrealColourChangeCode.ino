#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


// Which pin on the Arduino is connected to the Neostrip?
#define LED_PIN  3 // On Trinket or Gemma, suggest changing this to 1
#define LED_PIN2 6

// How many Neostrip are attached to the Arduino?
#define LED_COUNT 5 // Popular NeoPixel ring size
#define LED_COUNT2 8

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT2, LED_PIN2, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip(NUMstrip, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between strip


boolean green;
boolean red;
boolean blue;
boolean white;

int RGBStrip = 0;
int whiteStrip = 0;
int RGBCount = 5;
int whiteCount = 8;
int offStrip = -1;

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 100;   //Delaytime

unsigned long previousWhiteMillis = 0;        // will store last time LED was updated
const long whiteInterval = 500;   //Delaytime


void setup() {
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.clear(); // Set all pixel colors to 'off'
  strip2.clear(); // Set all pixel colors to 'off'
  Serial.begin(19200);
  Serial.setTimeout(6);
}

void loop() {

  if (!Serial.available()){
  
  String str = Serial.readString();

  
  if(str == "collisiongreen"){
 
            green = true;
            RGBStrip = 0;
   
  }else if(str == "collisionred"){

            red = true;
            RGBStrip = 0;
   
  }else if(str == "collisionblue"){
    
            blue = true;
            RGBStrip = 0;
    
  }else if(str == "collisionwhite"){

            white = true;
            whiteStrip = 0;
    
  }else if(str == "endfade"){

       green = false;
       red = false;
       blue = false;

    for(int i=0; i<LED_COUNT; i++) { // For each pixel...

      strip.setPixelColor(i, strip.Color(0, 0, 0));
  
      strip.show();   // Send the updated pixel colors to the hardware.
      
    }
      

  }else if(str == "end"){

       green = false;
       red = false;
       blue = false;

    for(int i=0; i<LED_COUNT2; i++) { // For each pixel...

      strip2.setPixelColor(i, strip2.Color(0, 0, 0));
  
      strip2.show();   // Send the updated pixel colors to the hardware.
      
    }
    offStrip=-1;
    whiteStrip=0;
     
  }else if(str == "endplay"){

       green = false;
       red = false;
       blue = false;

    for(int i=0; i<LED_COUNT; i++) { // For each pixel...

      strip.setPixelColor(i, strip.Color(0, 0, 0));
  
      strip.show();   // Send the updated pixel colors to the hardware.
      
    } for(int i=0; i<LED_COUNT2; i++) { // For each pixel...

      strip2.setPixelColor(i, strip2.Color(0, 0, 0));
  
      strip2.show();   // Send the updated pixel colors to the hardware.
      
      }
      offStrip=-1;
      whiteStrip=0;
    
     }
 
}

setLights();
setWhiteLights();

}

void setLights () {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  
    if(green == true){

      if(RGBStrip <= RGBCount){

      strip.setPixelColor(RGBStrip, strip.Color(0, 255, 0));
      strip.show();
      RGBStrip++;
      }
    
    }else if(blue == true){

      if(RGBStrip <= RGBCount){

      strip.setPixelColor(RGBStrip, strip.Color(0, 0, 255));
      strip.show();
      RGBStrip++;
      }
    
    }else if(red == true){

      if(RGBStrip <= RGBCount){

      strip.setPixelColor(RGBStrip, strip.Color(255, 0, 0));
      strip.show();
      RGBStrip++;
      }
    
    }


  }

    //strip2.setPixelColor(i, strip2.Color(0, 0, 0));

   // strip2.show();

   // strip.setPixelColor(i, strip.Color(0, 0, 0));

   // strip.show();
  
  
}

void setWhiteLights () {

  unsigned long currentWhiteMillis = millis();
  
  if (currentWhiteMillis - previousWhiteMillis >= whiteInterval) {
    // save the last time you blinked the LED
    previousWhiteMillis = currentWhiteMillis;

      if(white == true){

        if(whiteStrip <= whiteCount){

          strip2.setPixelColor(whiteStrip, strip2.Color(255, 255, 255));
          strip2.show();
          whiteStrip++;
     
      
      }
      if (offStrip <= whiteCount) {
        strip2.setPixelColor(offStrip, strip2.Color(0, 0, 0));
        strip2.show();
        offStrip++;
      }

      if (whiteStrip >= whiteCount && offStrip >= whiteCount){
        offStrip=-1;
        whiteStrip=0;
        
        }

    }

  }

}
