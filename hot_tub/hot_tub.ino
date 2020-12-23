#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
double val;
int pot_pin = 2, pump_state_change = 0;
String pump_state;

void setup() {
  lcd.begin();
  lcd.backlight();

}

void loop() {
  double temp_demand = 40*analogRead(pot_pin)/669;
  double temp_actual = 31.8;

  if (temp_actual<temp_demand){
    if (pump_state == "off"){
      pump_state_change = 1;}
    else{
      pump_state_change = 0;}
    pump_state = "on";}
  else{
    if (pump_state == "on"){
      pump_state_change = 1;}
    else{
      pump_state_change = 0;}
    pump_state = "off";}

  update_home_screen(temp_actual,temp_demand,pump_state,pump_state_change);
}

void update_home_screen(double temp_actual,double temp_demand, String pump_state, int pump_state_change){
  lcd.setCursor(0,0);
  lcd.print("Temp actual: " + String(temp_actual));
  lcd.setCursor(0,1);
  lcd.print("Temp demand: " + String(temp_demand));
  lcd.setCursor(0,2);
  if (pump_state_change)
    lcd.print("Pump state:    ");
  lcd.setCursor(0,2);
  lcd.print("Pump state: " + pump_state);
}

double temp_actual = get_hottub_temp(){
}
}
