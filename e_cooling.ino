void rotate(int a[], bool dir){
  // motor pins a[0],a[1],a[2],a[3]
  pinMode(a[0],OUTPUT);
  pinMode(a[1],OUTPUT);
  pinMode(a[2],OUTPUT);
  pinMode(a[3],OUTPUT);
  if(dir){
    switch(step_number){
      case 0:
      digitalWrite(a[0],HIGH);
      digitalWrite(a[1],LOW);
      digitalWrite(a[2],LOW);
      digitalWrite(a[3],LOW);
      break;
      case 1:
      digitalWrite(a[0],LOW);
      digitalWrite(a[1],HIGH);
      digitalWrite(a[2],LOW);
      digitalWrite(a[3],LOW);
      break;
      case 2:
      digitalWrite(a[0],LOW);
      digitalWrite(a[1],LOW);
      digitalWrite(a[2],HIGH);
      digitalWrite(a[3],LOW);
      break;
      case 3:
      digitalWrite(a[0],LOW);
      digitalWrite(a[1],LOW);
      digitalWrite(a[2],LOW);
      digitalWrite(a[3],HIGH);
      break;
    }
  }
  else{
    switch(step_number){
      case 0:
      digitalWrite(a[0],LOW);
      digitalWrite(a[1],LOW);
      digitalWrite(a[2],LOW);
      digitalWrite(a[3],HIGH);
      break;
      case 1:
      digitalWrite(a[0],LOW);
      digitalWrite(a[1],LOW);
      digitalWrite(a[2],HIGH);
      digitalWrite(a[3],LOW);
      break;
      case 2:
      digitalWrite(a[0],LOW);
      digitalWrite(a[1],HIGH);
      digitalWrite(a[2],LOW);
      digitalWrite(a[3],LOW);
      break;
      case 3:
      digitalWrite(a[0],HIGH);
      digitalWrite(a[1],LOW);
      digitalWrite(a[2],LOW);
      digitalWrite(a[3],LOW);
      break;
  }
  }
  step_number++;
  if(step_number>3){
    step_number=0;
  }
}

int check_temp(int pin){
  DHT.read11(pin);
  return DHT.temperature;
}
