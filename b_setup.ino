void setup(){
Serial.begin(9600);
GPRS.begin(9600);
lcd.backlight();
lcd.init();
myservo.attach(9);
curt.attach(3);
delay(500);
}
