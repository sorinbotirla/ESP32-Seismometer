#include <SPI.h>
#include <TFT_eSPI.h>
#include <Adafruit_ADS1X15.h>
#include <FastLED.h>
// #include <WiFi.h>
// #include <HTTPClient.h>
// #include "soc/soc.h"
// #include "soc/rtc_cntl_reg.h"
// #include "base64.h"


// #define WIFI_SSID "YOUR_WIFI_SSID"
// #define WIFI_PASS "YOUR_WIFI_PASSWORD"


// String serverName = "http://your-server";

// String httpRequestData = "";


#define LED_PIN 25 // THE LED DATA PIN
#define NUM_LEDS 7
#define START_LED 0

CRGB leds[NUM_LEDS];

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);  // Off-screen drawing buffer

// display and ads are working on 3.3V
// ADS1115 SDA 21
// ADS1115 SCL 22

// #define TFT_MISO 19 // Matching T_DO
// #define TFT_MOSI 23 // Matching T_DIN
// #define TFT_SCLK 18 // Matching T_CLK
// #define TFT_CS   17  // Chip select control pin
// #define TFT_DC   16  // Data Command control pin
// #define TFT_RST   5  // Reset pin (could connect to RST pin)
// #define TFT_BL   15  // LED back-light (only for ST7789 with backlight control pin)
// #define TOUCH_CS 33     // Chip select pin (T_CS) of touch screen


#define SPEAKER_PIN 4
#define RESOLUTION 8     // 8-bit resolution

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_SIZE 2

Adafruit_ADS1015 ads;
const int BUFFER_SIZE = 320;
float buffer[BUFFER_SIZE];
int bufferIndex = 0;
uint32_t lastTimeSoundStartup = millis();
uint32_t lastTimeSoundEvent = millis();
int startupDone = 0;

int smallEvents = 0;
int medEvents = 0;
int largeEvents = 0;
int minEvents = 0;
int triggered = 0;
int playing = 0;
int smallEventsTrigger = 4;
int medEventsTrigger = 10;
int largeEventsTrigger = 50;

unsigned long previousMillisDelayBetweenLeds = 0;
unsigned long previousMillisDelayBetweenSwipes = 0;
int currentLed = -1;

void setup() {
  // // WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  // // delay(100);

  // WiFi.mode(WIFI_STA); //Optional
  // WiFi.begin(WIFI_SSID, WIFI_PASS);
  // Serial.println("\nConnecting");

  // while(WiFi.status() != WL_CONNECTED){
  //     Serial.print(".");
  //     delay(500);
  // }

  // Serial.println("\nConnected to the WiFi network");
  // Serial.print("Local ESP32 IP: ");
  // Serial.println(WiFi.localIP());

  
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.show();

  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  sprite.setColorDepth(8);  // 8-bit color to reduce memory usage
  sprite.createSprite(SCREEN_WIDTH, SCREEN_HEIGHT);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawCentreString("Seismometer is starting", SCREEN_WIDTH / 2, 30, FONT_SIZE);

  ledcAttach(SPEAKER_PIN, 2200, RESOLUTION);

  Serial.begin(115200);
  ads.setGain(GAIN_SIXTEEN);
  // ads.setDataRate(RATE_ADS1115_475SPS);
  ads.setDataRate(RATE_ADS1115_128SPS);

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }

  startUpSound();
  lastTimeSoundStartup = millis();
  lastTimeSoundEvent = millis();
}

void turnOffLeds(){
  for (int p = 0; p <= NUM_LEDS; p++) {
      leds[p] = CRGB(0, 0, 0);
  }
  FastLED.show();
}

void swipeLedStripForward(CRGB color = CRGB(255, 255, 255), int startLed = 0, int endLed = 0, int delayBetweenLeds = 50, int delayBetweenSwipes = 100) {
  if ((unsigned long)(millis() - previousMillisDelayBetweenSwipes) >= delayBetweenSwipes) {
    if ((unsigned long)(millis() - previousMillisDelayBetweenLeds) >= delayBetweenLeds) {
      if (currentLed <= 0) {
        currentLed = startLed;
      }
      previousMillisDelayBetweenLeds = millis();
      if (currentLed >= startLed && currentLed <= endLed) {
        leds[currentLed] = color;
      }

      for (int p = 0; p <= NUM_LEDS; p++) {
        if (p != currentLed) {
          leds[p] = CRGB(0, 0, 0);
        }
      }
      FastLED.show();
      currentLed++;
      if (currentLed <= 0 || currentLed >= endLed || currentLed < startLed) {
        currentLed = startLed;
        previousMillisDelayBetweenSwipes = millis();
      }
    }
  }
}

void startUpSound(){
  ledcWriteTone(SPEAKER_PIN, 2200);
  delay(50);
  ledcWriteTone(SPEAKER_PIN, 0);
  delay(20);
  ledcWriteTone(SPEAKER_PIN, 4200);
  delay(50);
  ledcWriteTone(SPEAKER_PIN, 0);
  delay(20);
  ledcWriteTone(SPEAKER_PIN, 6200);
  delay(50);
  ledcWriteTone(SPEAKER_PIN, 0);
}

void smallEventSound(){
  if (playing == 0) {
    ledcWriteTone(SPEAKER_PIN, 6200);
    playing = 1;
  }
  if (millis() - lastTimeSoundEvent > 100) {
    ledcWriteTone(SPEAKER_PIN, 0);
    playing = 0;
  }
}

void mediumEventSound(){
  if (playing == 0) {
    ledcWriteTone(SPEAKER_PIN, 4200);
    playing = 1;
  }
  if (millis() - lastTimeSoundEvent > 300) {
    ledcWriteTone(SPEAKER_PIN, 0);
    playing = 0;
  }
}

void largeEventSound(){
  if (playing == 0) {
    ledcWriteTone(SPEAKER_PIN, 2200);
    playing = 1;
  }
  if (millis() - lastTimeSoundEvent > 800) {
    ledcWriteTone(SPEAKER_PIN, 0);
    playing = 0;
  }
}

void loop() {
  static int plotCounter = 0;
  float multiplier = 0.1875F;

  // int16_t raw = ads.readADC_Differential_0_1();
  float raw = ads.readADC_Differential_0_1();
  float voltage = raw * multiplier;

  buffer[bufferIndex] = voltage;
  bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
  plotCounter++;

  smallEvents = 0;
  medEvents = 0;
  largeEvents = 0;

  if (plotCounter >= 128) {
    plotCounter = 0;

    float minVal = buffer[0];
    float maxVal = buffer[0];
    for (int i = 1; i < BUFFER_SIZE; i++) {
      if (buffer[i] < minVal) minVal = buffer[i];
      if (buffer[i] > maxVal) maxVal = buffer[i];
    }

    float range = maxVal - minVal;
    if (range < 6) {
      float mid = (maxVal + minVal) / 2.0;
      minVal = mid - 3;
      maxVal = mid + 3;
      range = 6;
    }

    sprite.fillSprite(TFT_BLACK);

    // Draw Y-axis
    int axisX = 30;
    sprite.drawLine(axisX, 0, axisX, SCREEN_HEIGHT, TFT_WHITE);

    // Draw ticks and labels
    int ticks = 5;
    int lastLabelY = -100; // to prevent overlap

    for (int i = 0; i <= ticks; i++) {
      int y = map(i, 0, ticks, 0, SCREEN_HEIGHT);
      float value = maxVal - i * (range / ticks);
      int valueInt = (int)value;

      sprite.drawFastHLine(axisX - 5, y, 5, TFT_WHITE);

      // Avoid overlapping labels
      if (abs(y - lastLabelY) > 12) {
        sprite.setCursor(0, y - 7);
        sprite.setTextColor(TFT_WHITE, TFT_BLACK);
        sprite.setTextSize(1);

        if (range <= 50)
          sprite.printf("%s", ((String)valueInt));
        else
          sprite.printf("%s", ((String)valueInt));

        lastLabelY = y;
      }
    }

    // Always draw 0 label if it's within the visible range
    if (minVal <= 0 && maxVal >= 0) {
      int zeroY = SCREEN_HEIGHT - ((0.0 - minVal) * SCREEN_HEIGHT / range);
      if (abs(zeroY - lastLabelY) > 12) {
        sprite.drawFastHLine(axisX - 5, zeroY, 5, TFT_WHITE);
        sprite.setCursor(0, zeroY - 7);
        sprite.setTextColor(TFT_WHITE, TFT_BLACK);
        sprite.setTextSize(1);
        sprite.print("0");
      }
    }

    // Draw waveform

    for (int i = 1; i < BUFFER_SIZE; i++) {
      int prevIndex = (bufferIndex + i - 1) % BUFFER_SIZE;
      int currIndex = (bufferIndex + i) % BUFFER_SIZE;

      float v1 = buffer[prevIndex];
      float v2 = buffer[currIndex];

      if (v1 >= smallEventsTrigger && v1 < medEventsTrigger) {
        smallEvents++;
      } else if (v1 >= medEventsTrigger && v1 < largeEventsTrigger) {
        medEvents++;
      } else if (v1 >= largeEventsTrigger) {
        largeEvents++;
      }

      int x1 = i - 1 + axisX;
      int x2 = i + axisX;

      int y1 = SCREEN_HEIGHT - ((v1 - minVal) * SCREEN_HEIGHT / range);
      int y2 = SCREEN_HEIGHT - ((v2 - minVal) * SCREEN_HEIGHT / range);

      // if (((v1 - minVal) * SCREEN_HEIGHT / range) > SCREEN_HEIGHT && ((v2 - minVal) * SCREEN_HEIGHT / range) > SCREEN_HEIGHT) {
      //   sprite.drawLine(x1, v1 + 120, x2, v2 + 120, TFT_YELLOW);
      // } else {
      //   sprite.drawLine(x1, y1, x2, y2, TFT_YELLOW);
      // }

      sprite.drawLine(x1, y1, x2, y2, TFT_YELLOW);
    }

    sprite.pushSprite(0, 0);

    if (largeEvents > minEvents) {
      if (triggered == 0) {
        lastTimeSoundEvent = millis();
        triggered = 1;
      }
    } else if (medEvents > minEvents) {
      if (triggered == 0) {
        lastTimeSoundEvent = millis();
        triggered = 1;
      }
    } else if (smallEvents > minEvents) {
      if (triggered == 0) {
        lastTimeSoundEvent = millis();
        triggered = 1;
      }
    } else if (largeEvents == 0 && medEvents == 0 && smallEvents == 0) {
      triggered = 0;
      turnOffLeds();
    }

    Serial.println("largeEvents:"+((String) largeEvents)+", medEvents: "+((String) medEvents)+", smallEvents: "+((String) smallEvents)+", triggered: "+((String) triggered));

    // if(WiFi.status()== WL_CONNECTED){
    //   WiFiClient client;
    //   HTTPClient http;
    //   http.begin(client, serverName);
    //   http.addHeader("Content-Type", "application/json");
    //   httpRequestData = "[";
    //   for (int i = 1; i < BUFFER_SIZE; i++) {
    //     httpRequestData = httpRequestData + ((String) buffer[i]);
    //     if (i < BUFFER_SIZE) {
    //       httpRequestData = httpRequestData + ",";
    //     } else {
    //       httpRequestData = httpRequestData + "]";
    //     }
    //   }

      // base64 b;
      // String encodedHttpRequestData = b.encode((unsigned char *)httpRequestData.c_str(), strlen(httpRequestData.c_str())); 

      // int httpResponseCode = http.POST("?p="+((String)encodedHttpRequestData));
      // Serial.println(httpRequestData);
    // }
  }

  if (largeEvents > minEvents) {
    largeEventSound();  
    swipeLedStripForward(CRGB(255, 0, 0), 0, 7, 30, 300);
  } else if (medEvents > minEvents) {
    mediumEventSound();
    swipeLedStripForward(CRGB(255, 255, 0), 0, 7, 30, 300);
  } else if (smallEvents > minEvents) {
    smallEventSound();
    swipeLedStripForward(CRGB(0, 255, 0), 0, 7, 30, 300);
  } else if (largeEvents == 0 && medEvents == 0 && smallEvents == 0) {
    if (playing == 1) {
      ledcWriteTone(SPEAKER_PIN, 0);
      playing = 0;
      triggered = 0;
    }
  }
}