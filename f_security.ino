void interact() {
  // put your main code here, to run repeatedly:
 lcd.setCursor(0,0);
 lcd.print("Enter password");
 if(get_input()==1){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Welcome");
  clearData();
  tries=0;
  delay(500);
  lcd.clear();
 }
 if(get_input()==0){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Intruder");
  clearData();
  tries++;
  delay(500);
  lcd.clear();
 }
 alarm(buzzpin,13);

}

int  get_input(){
  char user_input;
  char customkey = customKeypad.getKey();
  if(customkey){
    FullPass[data_count]=customkey;
    lcd.setCursor(data_count,1);
    lcd.print(FullPass[data_count]);
    data_count+=1;
}
 if(data_count == Pass_length-1){
     if(!strcmp(FullPass, Master)){
      return 1;
      
     }
     else{
      return 0 ;
     }
     data_count =0;
  }
 
}
void clearData(){
  while (data_count != 0){
    FullPass[data_count--]=0;
  }
}
void alarm(int buzzerpin, int led){
  pinMode(buzzerpin,OUTPUT);
  digitalWrite(buzzerpin,HIGH);
    lights_blink(led);
  digitalWrite(buzzerpin,LOW);
  lights_off(led);
}
void check_gas(int gas, int buzz,int led){
  int SensorVal=analogRead(gas);
  if(SensorVal>450){
    printscreen("Gas detected",3);
    alarm(buzz,led);
  }
  else{
    digitalWrite(buzz,LOW);
    lights_off(led);
     printscreen("Gas detected",3);
  }
}
