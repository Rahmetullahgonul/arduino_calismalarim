//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
//sda a4 scl a5                      sda sda scl scl bağlasanda calısıyor.
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  // Print a message to the LCD.
 
  
}


void loop()
{
  
  lcd.setCursor(1,0);
  lcd.print("sevval");
  lcd.setCursor(10,0);
  lcd.print("karaca");
  delay(2000);
  lcd.clear();
  delay(2000);
  lcd.setCursor(6,0);
  lcd.print("cansu");
  lcd.setCursor(6,1);
  lcd.print("karaca");
  delay(2000);
  lcd.clear();
  delay(1000);
  
}
