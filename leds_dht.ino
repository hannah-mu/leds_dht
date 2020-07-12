#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

#define DEBUG 1

void setup() {

  Serial.begin(9600);

  dht.begin();
  
  strip.begin();
  strip.show();
  strip.setBrightness(100);
}

void loop() {

delay(2000);  
float f = dht.readTemperature(true);

  Serial.print(" Temperature: ");
  Serial.print(f);
  Serial.println("°F");
  
#ifdef DEBUG
Serial.println("FAIL");
#endif

if (f>=60) strip.setPixelColor(0, strip.Color(0, 10, 100));
if (f>=65) strip.setPixelColor(1, strip.Color(0, 10, 100));
if (f>=70) strip.setPixelColor(2, strip.Color(0, 10, 100));
if (f>=75) strip.setPixelColor(3, strip.Color(0, 10, 100));
if (f>=80) {strip.setPixelColor(4, strip.Color(100, 0, 100));
for(int i=0; i<4; i++){strip.setPixelColor(i, strip.Color(100, 0, 100));}}
if (f>=85) strip.setPixelColor(5, strip.Color(100, 0, 100));
if (f>=90) strip.setPixelColor(6, strip.Color(100, 0, 100));
if (f>=95) strip.setPixelColor(7, strip.Color(100, 0, 100));
if (f>=100) {strip.setPixelColor(8, strip.Color(100, 0, 10));
for(int i=0; i<8; i++){strip.setPixelColor(i, strip.Color(100, 0, 10));}}
if (f>=105) strip.setPixelColor(9, strip.Color(100, 0, 10));

strip.show();

#ifdef DEBUG
Serial.println("no");
#endif
}
