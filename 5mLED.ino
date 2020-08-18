#include <FastLED.h>

#define NUM_LEDS 293
#define DATA_PIN 7

CRGB leds[NUM_LEDS];

int setg[42];
int sety[21];
int subsetg[42];
int subsety[21];

void setup() { 
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812B,DATA_PIN,GRB>(leds,NUM_LEDS);
  LEDS.setBrightness(240);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,19000); 
  
  for(int i = 0; i < sizeof(setg)/sizeof(int); i++) {
    setg[i] = random16(0,NUM_LEDS-1);
  }
  for(int i = 0; i < sizeof(sety)/sizeof(int); i++) {
    sety[i] = random16(0,NUM_LEDS-1);
  }
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void RainbowCylon() { 
  static uint8_t hue = 0;
  Serial.print("x");
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show(); 
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }
  Serial.print("x");

  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }
}

void Cylon(int color) {
  static uint8_t hue = 0;
  Serial.print("x");
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i].setHue(color);
    FastLED.show(); 
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }
  Serial.print("x");
 
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    leds[i].setHue(color);
    FastLED.show();
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }  
}

void DoubleRainbowCylon() {
  static uint8_t hue = 0;
  int invertedi = 0;
  Serial.print("x");
  for(int i = 0; i < NUM_LEDS; i++) {
    invertedi = map(i,0,NUM_LEDS,NUM_LEDS,0);
    leds[i] = CHSV(hue++, 255, 255);
    leds[invertedi] = CHSV(hue++, 255, 255);
    FastLED.show(); 
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }
  Serial.print("x");

  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    invertedi = map(i,0,NUM_LEDS,NUM_LEDS,0);
    leds[i] = CHSV(hue++, 255, 255);
    leds[invertedi] = CHSV(hue++, 255, 255);
    FastLED.show();
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }  
}

void DoubleCylon(int color) {
  static uint8_t hue = 0;
  int invertedi = 0;
  Serial.print("x");
  for(int i = 0; i < NUM_LEDS; i++) {
    invertedi = map(i,0,NUM_LEDS,NUM_LEDS,0);
    leds[i].setHue(color);
    leds[invertedi].setHue(color);
    FastLED.show(); 
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }
  Serial.print("x");

  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    invertedi = map(i,0,NUM_LEDS,NUM_LEDS,0);
    leds[i].setHue(color);
    leds[invertedi].setHue(color);
    FastLED.show();
    // leds[i] = CRGB::Black;
    fadeall();
    delay(10);
  }   
}

void AlternatingBrightness() {
  for(int b = 0; b < 255; b++) {
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::White;
    }
    FastLED.delay(50);
    FastLED.setBrightness(b);
    Serial.println(b);
  }
  for(int b = 255; b > 0; b--) {
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::White;
    }
    FastLED.delay(50);
    FastLED.setBrightness(b);
    Serial.println(b);
  }
}

void FullRainbow(int delaytime) {
  for(int c = 0; c < 255; c++) {
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i].setHue(c);
    }
    FastLED.delay(delaytime);
  }
}

void Rumbler(int mode) {
  if(mode == 1) {
    for(int j = 0; j <= 3; j++) {
      for(int i = 0; i < NUM_LEDS/2; i++) {
        leds[i] = CRGB::Red;
      }
      FastLED.delay(75);
      for(int i = 0; i < NUM_LEDS/2; i++) {
        leds[i] = CRGB::Black;
      }
      FastLED.delay(25);
    }

    for(int j = 0; j <= 3; j++) {
      for(int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Blue;
      }
      FastLED.delay(75);
      for(int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
      }
      FastLED.delay(25);
    }

  }
  else if(mode == 2) {
    for(int i = 0; i < NUM_LEDS/2; i++) {
      leds[i] = CRGB::Red;
      leds[i + NUM_LEDS/2] = CRGB::Black;
    }
    FastLED.delay(250);
    
    for(int i = 0; i < NUM_LEDS/2; i++) {
      leds[i] = CRGB::Black;
      leds[i + NUM_LEDS/2] = CRGB::Blue;
    }
    FastLED.delay(250);
  }
  else if(mode == 3) {
    for(int i = 0; i < NUM_LEDS/4; i++) {
      
    }
  }
  else if(mode == 4) {
    
  }  
  else if(mode == 5) {
    
  }
  else if(mode == 6) {
    
  }
  else if(mode == 7) {
    
  }
  else if(mode == 8) {
    
  }
  else if(mode == 9) {
    
  }
  else if(mode == 10) {
    
  }
  else {
    FastLED.clear();
    FastLED.show();
  }
}

void ServerBlinking() {
  for(int i = 0; i < sizeof(setg)/sizeof(int); i++) { // bring back on green leds
    leds[setg[i]].setHue(96);
    FastLED.delay(25);
  }

  for(int i = 0; i < sizeof(sety)/sizeof(int); i++) { // bring back on yellow leds
    leds[sety[i]].setHue(64);
    FastLED.delay(25);
  }

  for(int i = 0; i < random8(0,10); i++) { // put off between 0 and 10 random green leds
    leds[setg[random8(0,sizeof(setg)/sizeof(int))]].setRGB(0,0,0);
  }
  FastLED.delay(500);

  for(int i = 0; i < random8(0,10); i++) { // make new subsetg
    subsetg[i] = setg[random8(0,sizeof(setg)/sizeof(int))];
  }

  int delaytime = random8(10,50);
  for(int j = 0; j < random8(0,21); j++) {
    for(int i = 0; i < sizeof(subsetg)/sizeof(int); i++) {
      leds[subsetg[i]].setRGB(0,0,0);
    }
    FastLED.delay(delaytime);
    for(int i = 0; i < sizeof(subsetg)/sizeof(int); i++) {
      leds[subsetg[i]].setHue(96);
    }
    FastLED.delay(delaytime);
  }
  FastLED.delay(random16(500,5000));

}

void createset(int par) {
  if(par == 1) {
    for(int i = 0; i < sizeof(setg)/sizeof(int); i++) {
      setg[i] = random16(0,NUM_LEDS-1);
    }
  }
  else if(par == 2) {
    for(int i = 0; i < sizeof(sety)/sizeof(int); i++) {
      sety[i] = random16(0,NUM_LEDS-1);
    }
  }
}

void loop() {
  //AlternatingBrightness();
  //FastLED.clear();
  //FastLED.show();
  //RainbowCylon();
  //FullRainbow(50);
  //Cylon(120);
  //DoubleRainbowCylon();
  //DoubleCylon(50);
  //Rumbler(0);
  //createset(1);
  //createset(2);
  ServerBlinking();
}
