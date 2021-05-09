#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


// Which pin on the Arduino is connected to the Neostrip?
#define LED_PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many Neostrip are attached to the Arduino?
#define LED_COUNT 5 // Popular NeoPixel ring size

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel strip(NUMstrip, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between strip

//const int buttonPin = 2;         // the number of the pushbutton pin
//int buttonState = LOW;         // variable for reading the pushbutton status

void setup() {
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.clear(); // Set all pixel colors to 'off'
  Serial.begin(9600);
  Serial.setTimeout(5);
//  pinMode(buttonPin, INPUT);
}

void loop() {

  
//if(buttonState == HIGH){
//     
//    Serial.println("button");
//    buttonState = LOW;
//    
//  }

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of strip minus one.
  if (!Serial.available()){
  
  String str = Serial.readString();

//  buttonState = digitalRead(buttonPin);

  
  if(str == "collisiongreen") {
    Serial.println("cleared");
    for(int i=0; i<LED_COUNT; i++) { // For each pixel...

    // strip.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    strip.setPixelColor(i, strip.Color(0, 150, 0));
    
    strip.show();   // Send the updated pixel colors to the hardware.
    delay(100);
    }
  }else if(str == "collisionred"){

    Serial.println("cleared");
    for(int i=0; i<LED_COUNT; i++) { // For each pixel...

    // strip.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a red color:
    strip.setPixelColor(i, strip.Color(150, 0, 0));

    strip.show();   // Send the updated pixel colors to the hardware.
    delay(100);
    }
    
  }else if(str == "collisionblue"){

    Serial.println("cleared");
    for(int i=0; i<LED_COUNT; i++) { // For each pixel...

    // strip.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a red color:
    strip.setPixelColor(i, strip.Color(0, 0, 150));

    strip.show();   // Send the updated pixel colors to the hardware.
    delay(100);
    }
    
  }else if(str == "end"){

    Serial.println("cleared");
    for(int i=0; i<LED_COUNT; i++) { // For each pixel...

    // strip.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a red color:
    strip.setPixelColor(i, strip.Color(0, 0, 0));

    strip.show();   // Send the updated pixel colors to the hardware.

    }
    
  }else if(str == "endfade"){

    Serial.println("cleared");
    for(int i=0; i<LED_COUNT; i++) { // For each pixel...

    // strip.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a red color:
    //strip.setPixelColor(i, strip.Color(0, 0, 0));

    //strip.show();   // Send the updated pixel colors to the hardware.
    //delay(50);
    }

  }
    
  }
  //delay(1000);

  
  
}
