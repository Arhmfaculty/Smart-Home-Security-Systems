
void lights_on(int pin){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,HIGH);
}
void lights_off(int pin){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}
void lights_blink(int pin){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,HIGH);
  delay(100);
  digitalWrite(pin,LOW);
  delay(100);
}

bool Day(int pin){
  pinMode(pin,INPUT);
  float sensorVal = analogRead(pin);
  float V = sensorVal/1023.*5.;
  Serial.println(V);
  delay(100);
  if (V>1.5){
    return true;
  }
  else{
    return false;
  }
}
