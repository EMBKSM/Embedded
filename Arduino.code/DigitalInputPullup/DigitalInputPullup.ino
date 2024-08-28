

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);//입력을 2번 핀으로 지정하나 PULL_UP저항을 사용
  pinMode(13, OUTPUT);//출력을 13번핀으로 지정
}

void loop() {
  int sensorVal = digitalRead(2);//2번핀의 상태를 sensorVal로 정의
  Serial.println(sensorVal);//sensorVal의 값을 출력(줄바꿈)
  if (sensorVal == HIGH) {//sensorVal의 값을 확인
    digitalWrite(13, LOW);//HIGH라면 LOW
  } else {
    digitalWrite(13, HIGH);//LOW라면 HIGH
  }
}
