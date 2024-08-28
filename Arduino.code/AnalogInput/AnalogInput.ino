

int sensorPin = A0;   // sensorPin을 A0핀으로 선언
int ledPin = 13;      // led핀을 13번으로 선언
int sensorValue = 0;  // sensorValue 선언 및 0으로 초기화

void setup() {
  pinMode(ledPin, OUTPUT); led핀(13번)을 출력으로 설정
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
}
