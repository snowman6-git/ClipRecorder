#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

void setup(void) {
  tft.init();
  tft.setRotation(1); //0 = 세로 1 = 가로 T/F

  
  // tft.drawRightString("Colour",75,64,4); // Right justified string drawing to x position 75
  // tft.setCursor(0, 0, 5);

  // tft.setTextColor(TFT_WHITE);
  
  // tft.setTextSize(1.2);
  // tft.println("bootup...");

}

void loop() {
  tft.fillScreen(TFT_BLACK);
  // tft.drawString("aa2 is loading", 75, 64, 4);
  tft.drawString("aa2 is work!", 75, 64, 4);
  delay(500);
  // tft.println("welcome!");
  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined

  
  // // Set the font colour to be yellow with no background, set to font 7
  // tft.setTextColor(TFT_YELLOW); tft.setTextFont(2);
  // tft.println(1234.56);
  
  // // Set the font colour to be red with black background, set to font 4
  // tft.setTextColor(TFT_RED,TFT_BLACK);    tft.setTextFont(4);
  // tft.println((long)3735928559, HEX); // Should print DEADBEEF

  // // Set the font colour to be green with black background, set to font 2
  // tft.setTextColor(TFT_GREEN,TFT_BLACK);
  // tft.setTextFont(2);
  // tft.println("Groop");

  // // Test some print formatting functions
  // float fnumber = 123.45;
  //  // Set the font colour to be blue with no background, set to font 2
  // tft.setTextColor(TFT_BLUE);    tft.setTextFont(2);
  // tft.print("Float = "); tft.println(fnumber);           // Print floating point number
  // tft.print("Binary = "); tft.println((int)fnumber, BIN); // Print as integer value in binary
  // tft.print("Hexadecimal = "); tft.println((int)fnumber, HEX); // Print as integer number in Hexadecimal
  // while(1) yield(); // We must yield() to stop a watchdog timeout.
}



