#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <Servo.h> 

Servo engine;

int detect1 = 2;
int detect2 = 3;

int Yer = 4;

int deger1 = 0;
int deger2 = 0;

void setup(){
  lcd.init();
  lcd.backlight();
  pinMode(detect1, INPUT);
  pinMode(detect2, INPUT);

  engine.attach(4);
  engine.write(180);

  lcd.setCursor(5,0);
  lcd.print(" RaSa ");
  lcd.setCursor(0,1);
  lcd.print("BELEDIYE OTOPARKI");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OTOPARKIMIZA");
  lcd.setCursor(0,1);
  lcd.print("HOSGELDINIZ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("otoparkta");
  lcd.setCursor(10,0);
  lcd.print(Yer);
  lcd.setCursor(0,1);
  lcd.print("yer vardir");
  delay(2000);
  lcd.clear();
  }
void loop(){
  
  if (digitalRead (detect1) == LOW && Yer >0 && deger1==0 && deger2==0){
    lcd.init();
    lcd.setCursor(0,1);
    lcd.print("HOSGELDINIZ");
    delay(300);
    lcd.clear();
    engine.write(90);
    Yer -= 1;
    lcd.setCursor(0,0);
    lcd.print("otoparkımzda");
    lcd.setCursor(0,1);
    lcd.print(Yer);
    lcd.setCursor(3,1);
    lcd.print("var");
    delay(1000);
    lcd.clear();
    deger1 += 1;
  }
 else if (digitalRead (detect2) == LOW && deger1 != 0){
    delay(2000);
    engine.write(180);
    deger1 -=1;
    }
  if (digitalRead (detect2) == LOW && deger2 ==0 && deger1==0){
    lcd.init();
    lcd.setCursor(0,0);
    lcd.print("yine bekleriz");
    delay(300);
    engine.write(90);
    Yer = Yer +1;
    if(Yer > 4){
    Yer = 4 ;} 
    lcd.setCursor(0,0);
    lcd.print("otoparkımzda");
    lcd.setCursor(0,1);
    lcd.print(Yer);
    lcd.setCursor(3,1);
    lcd.print("var");
    delay(1000);
    lcd.clear();
    deger2 += 1;
    }
  else if (digitalRead (detect1) == LOW && deger2 != 0){
    delay(2000);
    engine.write(180);
    deger2 -=1;
    }   
  if(digitalRead (detect1) == LOW && Yer<=0){
    lcd.init();
    lcd.setCursor(0,0);
    lcd.print("OTOPARKIMIZDA");
    lcd.setCursor(0,1);
    lcd.print("BOS YER YOK");
    } }
