#include <LiquidCrystal.h>
const int rs=4, en=6, d4=10 ,d5=11, d6=12, d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#include <IRremote.h>
IRrecv pult(7);
decode_results natija;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("   <<Nurbek>>");

  Serial.begin(9600);
  pult.enableIRIn();


}

void loop() {
  if (pult.decode(&natija)) {
    lcd.setCursor(2,1);
    lcd.print(natija.value, DEC);
    pult.resume();
    Serial.println(natija.value, DEC);
  }
}
  
