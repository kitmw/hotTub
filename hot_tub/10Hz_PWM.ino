void setup() {
unsigned long  tick_start_time = millis();
unsigned long  time_since_tick_start = 0;
int counter = 0;
pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
int PWM_array = {0 0 0 0 0 1 1 1 1 1};

time_since_last_tick = tick_start_time-millis();

if (time_since_last_tick >= 10){
  counter += 1;
  tick_start_time = millis();
  if(counter >= 10){
    counter = 0;
  }
}

digitalWrite(LED_BUILTIN,PWM_array[counter])
}
