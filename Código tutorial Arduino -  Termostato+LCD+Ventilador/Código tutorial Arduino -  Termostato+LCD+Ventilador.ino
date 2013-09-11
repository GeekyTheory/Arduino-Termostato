/*
  Autor: Mario Pérez Esteso
  Web: www.geekytheory.com
  Twitter: @geekytheory
  Facebook: www.facebook.com/geekytheory
*/

#include <LiquidCrystal.h>
#define beta 3950
#define resistance 2.8
float set=20.0;
int n=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  if(digitalRead(6))
  {
    set=set+0.1;
  }
  if(digitalRead(7))
  {
    set=set-0.1;
  }
  long a = analogRead(0);
  float temp1 = beta / (log(((1024.0 * resistance / a) - 2.8) / 2.8) + (beta / 298.0)) - 273.0;
  delay(50);
  float temp2 = beta / (log(((1024.0 * resistance / a) - 2.8) / 2.8) + (beta / 298.0)) - 273.0;
  delay(50);
  float temp3 = beta / (log(((1024.0 * resistance / a) - 2.8) / 2.8) + (beta / 298.0)) - 273.0;
  delay(50);
  float temp4 = beta / (log(((1024.0 * resistance / a) - 2.8) / 2.8) + (beta / 298.0)) - 273.0;
  delay(50);
  float temp5 = beta / (log(((1024.0 * resistance / a) - 2.8) / 2.8) + (beta / 298.0)) - 273.0;
  delay(50);
  float temp=(temp1+temp2+temp3+temp4+temp5)/5;
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(6, 0);
  lcd.print(temp);
  lcd.setCursor(12, 0);
  lcd.print((char)223);
  lcd.setCursor(13, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Set:  ");
  lcd.setCursor(6, 1);
  lcd.print(set);
  lcd.setCursor(12, 1);
  lcd.print((char)223);
  lcd.setCursor(13, 1);
  lcd.print("C");
  if(temp>set)
  {
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    lcd.setCursor(15,0);
    lcd.print("O");
    lcd.setCursor(15,1);
    lcd.print("N");
  } else if(set-temp<1 && temp<set)
  {
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    lcd.setCursor(15,0);
    lcd.print(" ");
    lcd.setCursor(15,1);
    lcd.print(" ");
  } else{
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    lcd.setCursor(15,0);
    lcd.print(" ");
    lcd.setCursor(15,1);
    lcd.print(" ");
  }
}
  
