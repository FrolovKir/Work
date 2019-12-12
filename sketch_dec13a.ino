#include <LiquidCrystal.h>
#define ECHO 3      // Прием сигнала с дальномера
#define TRIG 2        // Подача сигнала на дальномер
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
#define dist_setup 1  //Подстроечный коэффициент
#define  frequency 5000
 int n = 0;
void setup() 
{
    lcd.begin(16, 2);
   pinMode(ECHO, INPUT);     //...ECHO как вход...
   pinMode(TRIG, OUTPUT);
   Serial.begin(9600);  //Установим соединение с Serial
 
}
 
void loop() {
  digitalWrite(TRIG, HIGH);  //Подаем команду на дальномер
  digitalWrite(TRIG, LOW);
 
  int dist = pulseIn(ECHO, HIGH) / 54;  //Измеряем расстояние до объекта
 
  dist = constrain(dist, 2, 60);

  if(dist < 50 * dist_setup)
 {
    n += 120;
 }
 else {
  lcd.print( n );}
 }

