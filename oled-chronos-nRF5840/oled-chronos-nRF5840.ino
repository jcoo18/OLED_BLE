#include <nrf.h>
#include <nrf_gpio.h>
#include <nrf_delay.h>
#include <bluetooth.h>       // Example placeholder, replace with actual NRF Bluetooth library
#include <Adafruit_GFX.h>    // Graphics library for OLED
#include <Adafruit_SSD1306.h>// OLED library (ensure compatibility with your OLED model)

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String msg0, msg1, msg2, msg3, msg4, msg5;
int scroll = 0;


void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Initialize OLED display
  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  delay(2000);  // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Initialize Bluetooth
  // Add code to initialize Bluetooth for NRF5840
  // bt_init();

  // Initialize time (if using RTC or other time library)
  // rtc_init();
}

void loop() {
  display.clearDisplay();

  // Example of displaying time (you'll need to replace with your actual time logic)
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.print(F("Time: ")); display.println(getCurrentTime());

  // Example of displaying Bluetooth status
  display.print(F("Bluetooth: ")); display.println(getBluetoothStatus());

  // Display weather
  display.print(F("Weather: ")); display.println(getWeatherInfo());

  display.display();  // Actually display all of the above
  delay(1000);  // Wait 1 second before updating again
}

// Placeholder function for getting the current time
String getCurrentTime() {
  // Replace with actual time fetching logic
  return "12:34:56";
}

// Placeholder function for getting Bluetooth status
String getBluetoothStatus() {
  // Replace with actual Bluetooth status logic
  return "Connected";
}

// Placeholder function for getting weather information
String getWeatherInfo() {
  // Replace with actual weather fetching logic
  return "25C, Clear";
}

void copyMsg(String ms) {
  int msglen = ms.length();
  int lines = ceil(float(msglen) / 21);
  
  switch (lines) {
    case 1: msg0 = ms.substring(0, msglen); break;
    case 2: msg0 = ms.substring(0, 21); msg1 = ms.substring(21, msglen); break;
    case 3: msg0 = ms.substring(0, 21); msg1 = ms.substring(21, 42); msg2 = ms.substring(42, msglen); break;
    case 4: msg0 = ms.substring(0, 21); msg1 = ms.substring(21, 42); msg2 = ms.substring(42, 63); msg3 = ms.substring(63, msglen); break;
    case 5: msg0 = ms.substring(0, 21); msg1 = ms.substring(21, 42); msg2 = ms.substring(42, 63); msg3 = ms.substring(63, 84); msg4 = ms.substring(84, msglen); break;
    case 6: msg0 = ms.substring(0, 21); msg1 = ms.substring(21, 42); msg2 = ms.substring(42, 63); msg3 = ms.substring(63, 84); msg4 = ms.substring(84, 105); msg5 = ms.substring(105, msglen); break;
    default: break;
  }
}