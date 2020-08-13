#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#define echoPin 8
#define trigPin 9
int maximumRange = 200;
int minimumRange = 0;
long waktu,jarak;

void setup() {
  lcd.begin(16,2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);//buzz
}

void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
waktu=pulseIn(echoPin,HIGH);
jarak=waktu/58.2;
lcd.clear();
if (jarak<=30&&jarak>=14){
  digitalWrite(10,HIGH);digitalWrite(11,LOW);digitalWrite(12,LOW);lcd.setCursor(0,0);
  lcd.print("Jarak = ");lcd.print(jarak);lcd.print("cm");lcd.setCursor(1,1);
  lcd.print("Jarak Jauh");digitalWrite(13,LOW);
}
if (jarak<=14&&jarak>=5){
  digitalWrite(10,LOW);digitalWrite(11,HIGH);digitalWrite(12,LOW);lcd.setCursor(0,0);
  lcd.print("Jarak = ");lcd.print(jarak);lcd.print("cm");lcd.setCursor(1,1);
  lcd.print("Jarak Dekat");digitalWrite(13,HIGH);delay(250);digitalWrite(13,LOW);delay(250);
}
if (jarak<5){
  digitalWrite(10,LOW);digitalWrite(11,LOW);digitalWrite(12,HIGH);lcd.setCursor(0,0);
  lcd.print("Jarak = ");lcd.print(jarak);lcd.print("cm");lcd.setCursor(1,1);
  lcd.print("Jarak Ancaman");digitalWrite(13,HIGH);
}
}
