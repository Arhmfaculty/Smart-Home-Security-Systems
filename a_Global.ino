
// Libraries 
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <dht.h>
#include <Servo.h>


//Security System
#define  Pass_length 5
const byte ROWS = 4;
const byte COLS =4;
int data_count;
int tries=0;
char Master[Pass_length]="123A";
char FullPass[Pass_length];
char Keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


//Temperature
dht DHT;
int step_number=0;

//pins
int motor[] = {9,10,11,12};
int motor2[] = {9,10,11,12};
byte rowPins[ROWS]={9,8,7,6};
byte colPins[COLS]={5,4,3,2};
int buzzpin = 12;
SoftwareSerial GPRS(2,3);
int outside_lights = 4;
int inside_lights = 4;
int ashesi_lights = 13;
int LDR_pin = 5;
int sensor[] = {6,7};
int gas = A1;
long duration;
int distance;
int pos = 0;
int pos1=0;
void lights_on(int pin);
void opendoor();
int check_temp(int pin);
void check_gas(int gas, int buzz,int led);
void printscreen(String a, int b);
int measurDistance(int a[]);

Keypad customKeypad = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27,20,4);
Servo myservo;
Servo curt;
