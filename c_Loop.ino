
void loop(){
printscreen("SMART HOME", 0);
lights_on(ashesi_lights);
opendoor();
check_gas(gas,buzzpin,ashesi_lights);
lcd.clear();
}
