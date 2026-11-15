#include <Adafruit_NeoPixel.h>

#define LED_PIN 22
#define NUM_LEDS 1
#include <Mouse.h>
#include <Keyboard.h>

Adafruit_NeoPixel led(
  NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800
);

void setup() {
  led.begin();
  led.setBrightness(50);
  led.clear();
  led.show();
  Mouse.begin();
  Keyboard.begin();
}
void mouseorigen() {
  for (int i = 0; i < 60; i++) {
    Mouse.move( 100, -100, 0);
    delay(1);
  }
  Mouse.move(-10, 25,0);
  Mouse.click(MOUSE_LEFT);
}

void movermouse() {
  mouseorigen();
  for (int i = 0; i < 60; i++) {
    Mouse.move( 100, 100, 0);
    delay(1);  
  }
  Mouse.move(-40, -35, 0);
  Mouse.click(MOUSE_LEFT);
    // Presionar Ctrl + V
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  delay(100);
  MOuse
  // Soltar ambas teclas
  Keyboard.releaseAll();
  mouseorigen();

}

void loop() {
  
  // Esperar 10 segundos
  led.setPixelColor(0, led.Color(0, 0, 255));
  led.show();
  delay(10000);

  movermouse();
  // Mover el cursor a la derecha
  led.setPixelColor(0, led.Color(255, 0, 0));
  led.show();
  delay(100);

  // Esperar 100 milisegundos
  delay(500);



  // Regresar el cursor
}
