#include <Arduino.h>
#define MA_BROCHE_ANGLE 32 
#include <FastLED.h>
CRGB monPixel;


void setup() {
    Serial.begin(115200);
    FastLED.addLeds<WS2812,27,GRB>( & monPixel, 1 );
}

void loop() {
    int maLectureAnalogique;
   maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);
   Serial.print(maLectureAnalogique);
   Serial.println();
   delay(100);
   int red = maLectureAnalogique * 255 / 4095;
   monPixel = CRGB(red,0,0);
   FastLED.show();

   /*if (maLectureAnalogique < 2080){
    monPixel = CRGB (0, 0, 0);
    FastLED.show();
   }
   else {
    monPixel = CRGB (255, 0, 0);
    FastLED.show();
   }*/
}

