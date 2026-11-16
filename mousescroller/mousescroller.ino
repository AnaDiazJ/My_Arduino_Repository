#include <Adafruit_NeoPixel.h>

#define LED_PIN 22
#define NUM_LEDS 1
#include <Mouse.h>
#include <Keyboard.h>

Adafruit_NeoPixel led(
  NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800
);

// Scroll hacia abajo
void scrollHastaAbajo() {
  for (int i = 0; i < 20; i++) {
    Mouse.move(0, 0, -3);
    delay(50);
  }
}

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
 void movimientos(int x, int y) {
  Mouse.move(x, y, 0);
  Mouse.click(MOUSE_LEFT);

  delay(20);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  delay(30);

  Keyboard.releaseAll();
  Mouse.move(32,0 , 0);
  Mouse.click(MOUSE_LEFT);
 }

void movermouse() {
  mouseorigen();
  for (int i = 0; i < 60; i++) {
    Mouse.move( 100, 100, 0);
    delay(1);  
  }

  Mouse.move(0,-100,0);
  scrollHastaAbajo();
  Mouse.move(0,100,0);

  movimientos(-50, -40);
  Mouse.move(-32,0,0);
  movimientos(0,-20);
  delay(1);
  mouseorigen();
  Mouse.move(-400,-200.0);
}

void loop() {
  led.setPixelColor(0, led.Color(0, 0, 255));
  led.show();
  if (BOOTSEL) {
    delay(30);                 // antirrebote
    if (BOOTSEL) {
      movermouse();

      led.setPixelColor(0, led.Color(255, 0, 0));
      led.show();

      while (BOOTSEL) delay(10);  
    }
  }
}