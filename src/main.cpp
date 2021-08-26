#include <Arduino.h>
#include <U8x8lib.h>
#include <WiFi.h> //Standard ESP32 Wifi Library

U8X8_SSD1306_128X64_NONAME_SW_I2C screen(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);
void setup() {
  //Initializing the display
  screen.begin();
  screen.setFont(u8x8_font_chroma48medium8_r);
  screen.clearDisplay();

  //Initializing the wifi station mode on the esp32
  WiFi.mode(WIFI_STA); 
  WiFi.disconnect();
  delay(100);
  screen.setCursor(0,0);
  screen.print("Station Mode !");
}
void loop() {
  //Scanning the networks
  screen.clear();
  screen.print("Scanning ...");
  int numberOfNetworks = WiFi.scanNetworks(); //Scannning the number of networks and storing the informaion;
  if(numberOfNetworks == 0) {
    screen.clear();
    screen.print("No Network");
  }
  else {
    screen.clear();
    screen.print("Net Found:- ");
    screen.println(numberOfNetworks);
    delay(1000);
  }
  for(int i=0; i<numberOfNetworks; i++) {
    //Clear the screen show we can iterate all the found networks in the small screen with 8 lines of limit
    if(i%8 == 0){
      screen.clear();
    }
    //Iterating all the networks and showing details
    screen.printf("%d. %.12s\n",i+1,WiFi.SSID(i).c_str());
    delay(1000);
  }
}