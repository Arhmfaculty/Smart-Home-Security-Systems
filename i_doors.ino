 void opendoor(){
    if(measurDistance(sensor)<= 20){
    for(pos=0;pos<=180;pos+=1){
      myservo.write(pos);
      delay(10);
      lcd.clear();
     printscreen("Opening door ...",2);
    }
    delay(5000);
    for(pos=180;pos>=0;pos-=1){
      myservo.write(pos);
      delay(10);
      lcd.clear();
     printscreen("Closing door...",2);
    }
  }
}
  int measurDistance(int a[]){
    //a[0] is trig a[1]echo
    pinMode(a[0],OUTPUT);
    digitalWrite(a[0],LOW);
    delayMicroseconds(2);
    digitalWrite(a[0],HIGH);
    delayMicroseconds(10);
    digitalWrite(a[0],LOW);
    pinMode(a[1],INPUT);
    duration = pulseIn(a[1],HIGH);
    distance = (duration/2)/29.1;
    return distance;
  }
