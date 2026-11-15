
#include <Adafruit_NeoPixel.h>

#define LED_PIN 22
#define NUM_LEDS 1
#include <Mouse.h>

Adafruit_NeoPixel led(
  NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800
);

void setup() {
  led.begin();
  led.setBrightness(50);
  led.clear();
  led.show();
  Mouse.begin();}

void loop() {
  // Esperar 10 segundos
  led.setPixelColor(0, led.Color(0, 0, 255));
  led.show();
  delay(10000);

  // Mover el cursor a la derecha
  Mouse.move(10, 0, 0);
  led.setPixelColor(0, led.Color(255, 0, 0));
  led.show();
  delay(100);


  // Esperar 100 milisegundos
  delay(100);

  // Regresar el cursor
  Mouse.move(-10, 0, 0);}
