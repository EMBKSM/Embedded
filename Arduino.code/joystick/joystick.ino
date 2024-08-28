int INA = 7;
int INB = 6;
int hanjanhe = 0;
int hanjanmothe = 0;
int flag = 0;
bool toggle_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  pinMode(INA,OUTPUT);
  pinMode(INB,OUTPUT);
}

void loop() {
  if(toggle_state){
    hanjanhe = analogRead(A1);
    hanjanmothe = analogRead(A0);
    digitalWrite(INA, map(hanjanhe, 0, 1023, 0, 255));
    digitalWrite(INB, map(hanjanmothe, 0, 1023, 0, 255));
  }
  

  if(digitalRead(8) == 0){
    if(flag == 0){
      flag = 1;
      toggle_state = !toggle_state;
      delay(500);
    }
  }
  else{
    if(flag == 1){
      flag = 0;
    }
  }
}
