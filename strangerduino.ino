#include <FastLED.h>
#define DATA_PIN 7
#define NUM_LEDS 100
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS];

int word_help [] = {25, 26, 27, 28, 29, 13, 14, 15, 50, 38, 37, 36};
int word_run [] = {71, 72, 73, 81, 82, 44, 43, 42};

void setup(){
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    randomSeed(analogRead(0));
}

void wordHandler(int *toDisplay, int arraySize) {
  // Disable anything we have lit
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black; FastLED.show();
  }
  // Light our chosen word
  for (int i = 0; i < arraySize; i++) {
    int position = toDisplay[i];
    leds[position] = CRGB::Red; FastLED.show();
    delay(3000);
  }
}

void christmas() {
  for (int i = 0; i < NUM_LEDS; i++) {
    int color = random(0,7);
    switch(color){
      case 0:
        leds[i] = CRGB::Chartreuse; FastLED.show();
        break;
      case 1:
        leds[i] = CRGB::Aqua; FastLED.show();
        break;
      case 2:
        leds[i] = CRGB::Crimson; FastLED.show();
        break;
      case 3:
        leds[i] = CRGB::DarkOrange; FastLED.show();
        break;
      case 4:
        leds[i] = CRGB::DarkOrange; FastLED.show();
        break;
      case 5:
        leds[i] = CRGB::Fuchsia; FastLED.show();
        break;
      case 6:
        leds[i] = CRGB::Red; FastLED.show();
        break;
      case 7:
        leds[i] = CRGB::GreenYellow; FastLED.show();
        break;
      default:
        leds[i] = CRGB::GreenYellow; FastLED.show();
        break;
    }
  }
}

void loop(){
  wordHandler(word_help, 12);
  delay(3000);
  christmas();
  delay(3000);
  wordHandler(word_run, 8);
  delay(3000);

}
