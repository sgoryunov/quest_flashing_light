#define BUTTON_PIN 2
#define LIGHT_ONE 10
#define LIGHT_TOW 11
#define LIGHT_THREE 12

const short lights_pin[3] = {LIGHT_ONE,LIGHT_TOW,LIGHT_THREE};
const short shoots[10] = {LIGHT_ONE,LIGHT_TOW,LIGHT_ONE,
                          LIGHT_THREE,LIGHT_ONE,LIGHT_TOW,
                          LIGHT_ONE,LIGHT_THREE,LIGHT_THREE,LIGHT_ONE};
bool isStartLight = false;
int sensorVal = LOW;

void setup() {

  //start serial connection
//  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  for(short pin:lights_pin){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void loop() {
  int cur_sensorVal = digitalRead(BUTTON_PIN);
  if(cur_sensorVal == LOW and sensorVal == HIGH){
    for(short pin:shoots){
      digitalWrite(pin, LOW);
      delay(1000);
      digitalWrite(pin, HIGH);
      delay(1000);
    }
  };
  sensorVal = cur_sensorVal; 
}
